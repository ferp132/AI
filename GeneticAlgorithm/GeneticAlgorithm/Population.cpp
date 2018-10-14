
#include "Population.h"

Population::Population(int Size, int MutRate, std::string Goal)
{
	PopSize = Size;
	MutationRate = MutRate;
	GoalPhrase = Goal;
	Generation = 0;
}

Population::~Population()
{
	delete[] PopArray;
	delete[] NextGeneration;
}

void Population::Init()
{
	srand((unsigned int)time(NULL));												//Create Random Seed
	PopArray = new DNA[PopSize];		
	NextGeneration = new DNA[PopSize];

	for (int i = 0; i < PopSize; i++)
	{
		PopArray[i].ResizePhrase(GoalPhrase.size());			//make sure all of the DNA strings are the same size as the goal phrase
		NextGeneration[i].ResizePhrase(GoalPhrase.size());
		for (int j = 0; j < GoalPhrase.size(); j++)
		{
			PopArray[i].SetPhraseAt((char)(32 + (rand() % (126 - 32))), j); //set each character to a random character in the ascii table
		}	
	}

	CalcFitness();
	while (MatingPool.size() < 5)
	{
		for (int i = 0; i < PopSize; i++)
		{
			for (int j = 0; j < GoalPhrase.size(); j++)
			{
				PopArray[i].SetPhraseAt((char)(32 + (rand() % (126 - 32))), j); //set each character to a random character in the ascii table
			}
		}
		CalcFitness();
	}
}

void Population::ProcessGenAlg()
{
	while (BestDNA.GetPhrase().compare(GoalPhrase))
	{
		Draw();

		//reset
		MatingPool.clear();
		for(int i = 0; i < PopSize; i++)
			PopArray[i].SetScore(0);
		//-----

		CalcFitness();
		Select();
		Generation++;
		Sleep(1000);
	}
}

void Population::CalcFitness()
{

	for (int i = 0; i < PopSize; i++)
	{
		
		for (int j = 0; j < GoalPhrase.size(); j++)
		{
			if (PopArray[i].GetPhrase().at(j) == GoalPhrase.at(j))
			{
				std::cout << "Score++";
				PopArray[i].IncrementScore();
				MatingPool.push_back(i);
			}
		}

		if (PopArray[i].GetScore() > BestDNA.GetScore())
			BestDNA = PopArray[i];
	}
}

void Population::Select()
{
//	for (int i = 0; i < MatingPool.size(); i++)
//		std::cout << MatingPool.at(i) << ", ";

	for (int i = 0; i < PopSize; i++)
	{
		int FirstDNA = MatingPool.at(rand() % MatingPool.size());
		int SecondDNA = MatingPool.at(rand() % MatingPool.size());

		while (FirstDNA == SecondDNA)
		{
			SecondDNA = MatingPool.at(rand() % MatingPool.size());
		}

		Breed(FirstDNA, SecondDNA, i);
	}

	for (int i = 0; i < PopSize; i++)
	{
		PopArray[i] = NextGeneration[i];
	}
}

void Population::Breed(int First, int Second, int Pos)
{
	int Selection = (rand() % (GoalPhrase.size() - 1)) + 1;

	std::string NewPhrase = PopArray[First].GetPhrase().substr(0, Selection);
	NewPhrase.append(PopArray[Second].GetPhrase().substr(Selection, std::string::npos));

	for (int i = 0; i < NewPhrase.size(); i++)
	{
		if (rand() % 100 <= MutationRate);
		{
			NewPhrase.at(i) = (char)(32 + (rand() % (126 - 32)));
		}
	}

	NextGeneration[Pos].SetPhrase(NewPhrase);
}

void Population::Draw()
{
	system("CLS");

	std::cout << "Current Generation: " << Generation << "     ||     " << " Goal Phrase: " << GoalPhrase << "     ||     " << "Best Phrase: " << BestDNA.GetPhrase() << std::endl << std::endl;

	for (int i = 0; i < PopSize; i++)
	{
		std::cout << "Phrase " << i << ":     " << PopArray[i].GetPhrase() << " Score: " << PopArray[i].GetScore() << std::endl;
	}
}
