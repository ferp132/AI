//				Media Design School
//Author:		Louis Cresswell
//email:		louiscresswell33@gmail.com
//Submitted:	16/10/2018
//For Program:	Genetic Algorithm
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
		PopArray[i].ResizePhrase(GoalPhrase.size());								//make sure all of the DNA strings are the same size as the goal phrase
		NextGeneration[i].ResizePhrase(GoalPhrase.size());
		for (int j = 0; j < GoalPhrase.size(); j++)
		{
			PopArray[i].SetPhraseAt((char)(32 + (rand() % (126 - 32))), j);			//set each character to a random character in the ascii table
		}	
	}

	//this loop makes sure we start of with a decent set of random phrases
	CalcFitness();
	while (MatingPool.size() < 5)
	{
		MatingPool.clear();
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
		//reset
		MatingPool.clear();
		for(int i = 0; i < PopSize; i++)
			PopArray[i].SetScore(0);
		//-----

		CalcFitness();
		Draw();
		Select();
		Generation++;
	//	Sleep(10);
	}
	DrawComplete();
}

void Population::CalcFitness()
{
	GenScore = 0;
	//loop through each item in pop
	for (int i = 0; i < PopSize; i++)
	{
		//check each character in the phrase
		for (int j = 0; j < GoalPhrase.size(); j++)
		{
			//if it matches the final phase, incriment the score and add it to the mating pool once
			if (PopArray[i].GetPhrase().at(j) == GoalPhrase.at(j))
			{
				PopArray[i].IncrementScore();
				MatingPool.push_back(i);
				GenScore++;
			}
		}
		//check if this phrase is better than the current best phrase
		if (PopArray[i].GetScore() > BestDNA.GetScore())
			BestDNA = PopArray[i];
	}
	//make average
	GenScore = GenScore / PopSize;
}

void Population::Select()
{
	//loop thogu has many times as there are population members
	for (int i = 0; i < PopSize; i++)
	{
		//choose two members of the mating pool
		int FirstDNA = MatingPool.at(rand() % MatingPool.size());
		int SecondDNA = MatingPool.at(rand() % MatingPool.size());
		//make sure theyre not the same
		while (FirstDNA == SecondDNA)
		{
			SecondDNA = MatingPool.at(rand() % MatingPool.size());
		}
		//merge them together
		Breed(FirstDNA, SecondDNA, i);
	}

	//move the next generation to the main generations array
	for (int i = 0; i < PopSize; i++)
	{
		PopArray[i] = NextGeneration[i];
	}
}

void Population::Breed(int First, int Second, int Pos)
{
	//choose a random midpoint
	int Selection = (rand() % (GoalPhrase.size() - 1)) + 1;
	//int Selection = GoalPhrase.size() / 2;

	//create a new phrase
	std::string NewPhrase = PopArray[First].GetPhrase().substr(0, Selection);
	//add to the new phrase
	NewPhrase.append(PopArray[Second].GetPhrase().substr(Selection, std::string::npos));

	//-----Mutate
	for (int i = 0; i < NewPhrase.size(); i++)
	{
		int MutateChance = rand() % 100;
		if (MutateChance < MutationRate)
		{
			NewPhrase.at(i) = (char)(32 + (rand() % (126 - 32)));
		}
	}

	//set the phrase
	NextGeneration[Pos].SetPhrase(NewPhrase);
}

void Population::Draw()
{
	DrawBanner();

	int PrintNo;

	if (PopSize < 30) PrintNo = PopSize;
	else PrintNo = 30;

	std::cout << "Phrases: (first " << PrintNo << ")" << std::endl;

	for (int i = 0; i < PrintNo; i++)
	{
		std::cout << "     " << PopArray[i].GetPhrase() << "   ||   " << "Score: " << PopArray[i].GetScore() << std::endl;
	}

	std::cout << "     ";
	for (int i = 0; i < GoalPhrase.size(); i++)
		std::cout << " ";
	std::cout << "   ||   " << "Average Score: ";
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	std::cout << GenScore;

	std::cout << std::endl << std::endl;
	std::cout << "     Current Generation: " << Generation;

	std::cout << "   ||   " << "Best Phrase: " << BestDNA.GetPhrase() << std::endl << std::endl;
}

void Population::DrawComplete()
{
	DrawBanner();

	std::cout << " Algorithm Complete!" << std::endl << std::endl;
	std::cout << " It took the program " << Generation << " generations to complete" << std::endl;

	std::cout << "Press enter to return...";
	std::cin.ignore();
	std::cin.get();
}

void Population::DrawBanner()
{
	system("CLS");

	for (int i = 0; i < 125; i++)
		std::cout << "=";
	std::cout << std::endl;

	std::cout << std::endl << std::endl << "                              Welcome to Louis' Genetic Algorithm" << std::endl << std::endl << std::endl;

	for (int i = 0; i < 125; i++)
		std::cout << "=";
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "               Goal Phrase: " << GoalPhrase << "   ||   " << "Population Size: " << PopSize << "   ||   " << "Mutation Rate: " << MutationRate << std::endl << std::endl;
	
	for (int i = 0; i < 125; i++)
		std::cout << "=";
	std::cout << std::endl;

}

