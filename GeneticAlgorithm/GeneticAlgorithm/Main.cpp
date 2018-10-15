//				Media Design School
//Author:		Louis Cresswell
//email:		louiscresswell33@gmail.com
//Submitted:	16/10/2018
//For Program:	Genetic Algorithm

//-----Library Includes
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

//-----Local Includes
#include "Population.h"

using namespace std;

//-----Function Declarations
void DrawMenu();
void DrawEqualsLine();
void DrawBanner();
void SetPop();
void SetMutRate();
void SetPhrase();
void PrintInstructions();
Population* pop;

int main(void)
{
	//----------Initialisation
	string Hello = "Hello There, ";
	string InitInput;
	srand(time((unsigned int)NULL));
	
	DrawEqualsLine();
	cout << endl << endl << "          Welcome to Louis' Genetic Algorithm" << endl << endl << endl;
	DrawEqualsLine();
	cout << endl << "     Please enter your name: ";
	getline(cin, InitInput);
	Hello.append(InitInput);
	pop = new Population(1000, 2, Hello);

	//----------Main Loop
	bool Exit = false;
	while (!Exit)
	{
		DrawMenu();
		int UserInput;

		//-----Get User Input
		cin >> UserInput;
		while (UserInput < 1 || UserInput > 6)
		{
			DrawMenu();
			cout << "Invalid Input! Try Again: ";
			cin >> UserInput;
		}
		//-----Process User Input
		switch (UserInput)
		{
		case 1:
		{
			pop->Init();
			pop->ProcessGenAlg();

			Population* Temp = pop;
			pop = new Population(pop->GetPopSize(), pop->GetMutRate(), pop->GetGoalPhrase());
			delete Temp;
			break;
		}
		case 2:
		{
			SetPop();
			break;
		}
		case 3:
		{
			SetMutRate();
			break;
		}
		case 4:
		{
			SetPhrase();
			break;
		}
		case 5:
		{
			PrintInstructions();
			break;
		}
		case 6:
		{
			Exit = true;
			break;
		}
		}
	}
	cin.get();
	delete pop;
	return 0;
}

void DrawBanner()
{
	system("CLS");
	DrawEqualsLine();
	cout << endl << endl <<  "                              Welcome to Louis' Genetic Algorithm" << endl << endl << endl;
	DrawEqualsLine();
	cout << endl;
	cout << "               Goal Phrase: " << pop->GetGoalPhrase() << "   ||   " << "Population Size: " << pop->GetPopSize() << "   ||   " << "Mutation Rate: " << pop->GetMutRate() << endl << endl;
	DrawEqualsLine();
}

void DrawMenu()
{
	DrawBanner();
	cout << endl;
	cout << "     " << "Main Menu: " << endl << endl;
	cout << "          " << "1) Begin Genetic Algorithm" << endl;
	cout << "          " << "2) Set Population Size " << endl;
	cout << "          " << "3) Set Mutation Rate " << endl;
	cout << "          " << "4) Set Goal Phrase" << endl;
	cout << "          " << "5) Instructions" << endl;
	cout << "          " << "6) Exit" << endl << endl;
	DrawEqualsLine();
	cout << "                    " << "Selection: ";
}

void DrawEqualsLine()
{
	for (int i = 0; i < 125; i++)
		cout << "=";
	cout << endl;
}

void SetPop()
{
	int UserInput;
	DrawBanner();
	cout << endl << "          Set Population to: ";
	cin >> UserInput;
	while (UserInput <= 0)
	{
		DrawBanner();
		cout << "          Invalid Input! " << endl;
		cout << endl << "          Set Population to: ";
		cin >> UserInput;
	}

	pop->SetPopSize(UserInput);
	return;
}

void SetMutRate()
{
	int UserInput;
	DrawBanner();
	cout << endl << "          Set Mutation Rate to (Percent): ";
	cin >> UserInput;
	while (UserInput < 0 || UserInput > 100)
	{
		DrawBanner();
		cout << "          Invalid Input! " << endl;
		cout << endl << "          Set Mutation Rate to (Percent): ";
		cin >> UserInput;
	}

	pop->SetMutationRate(UserInput);
	return;
}

void SetPhrase()
{
	string UserInput;
	DrawBanner();
	cout << endl << "          Set Phrase to: ";
	cin.ignore();
	getline(cin, UserInput);
	//while (UserInput < 0 || UserInput > 100)
	//{
	//	DrawBanner();
	//	cout << "          Invalid Input! " << endl;
	//	cout << endl << "          Set Population to (Percent): ";
	//	cin >> UserInput;
	//}

	pop->SetGoal(UserInput);
}

void PrintInstructions()
{
	DrawBanner();
	cout << endl << "     This program will use a genetic algorithm to generate a phrase matching the Goal Phrase. Initailly it will generate a number of phrases ";
	cout << endl << "     with random characters equal in length to the goal phrase. It will then asses the score of each of these phrases based on the number of";
	cout << endl << "     matching characters. It will then create the next generation population by selecting two parent phrases (randomly with a higher chance ";
	cout << endl << "     for better scoring phrases). When creating the next generation there is a chance that each character in each new phrase may mutate into ";
	cout << endl << "     another random character. it continues this process until a matching phrase has been found." << endl;
	cout << endl << "          Goal Phrase: The Phrase we are trying to generate" << endl;
	cout <<			"                    Longer phrases are more difficult to generate and take more generations to complete" << endl;
	cout << endl << "          Population Size: The number of phrases to generate each generation." << endl;
	cout <<			"                    Higher Population sizes tend to work better as there is a higher chance of generating a good match" << endl;
	cout << endl << "          Mutation Rate: Everytime a new phrase is made, there is a percentage chance that each character in that phrase will become ";
	cout << endl << "                         another random character. This prevents the Population from becoming top homogenous" << endl;
	cout <<			"                    Low mutaion rates will cause homogenousation, stopping any meaningful progress." << endl;
	cout <<			"                    High mutaion rates will cause the program to be more random. This can cause the algorithm to require drasitcally " << endl;
	cout <<			"                    more generations to complete" << endl;

	cout << endl << "     Press enter to return...";
	
	cin.ignore();
	cin.get();
	return;
}