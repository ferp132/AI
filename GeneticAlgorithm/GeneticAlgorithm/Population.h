#pragma once
//				Media Design School
//Author:		Louis Cresswell
//email:		louiscresswell33@gmail.com
//Submitted:	16/10/2018
//For Program:	Genetic Algorithm
//Purpose:		Stores all the information and functionallity for a genetic algorithm 
//				that generates a random set of phrases that eventually iterates to a goal phrase
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <Windows.h>
#include <iomanip>
#include "DNA.h"

class Population
{
public:
	//-----Con/Destructors
	Population(int Size, int MutRate, std::string Goal);	// Begin with a population size, Mutation rate & Goal Phrase
	~Population();

	//-----Algorithm
	void Init();											//Begin
	void ProcessGenAlg();									//Main Loop
	void CalcFitness();										//Claculates score
	void Select();											//Selects two parents from the mating pool & call breed function
	void Breed(int First, int Second, int Pos);				//Merges two parents int a child an mutates it

	//-----Draw Functions
	void Draw();
	void DrawComplete();
	void DrawBanner();

	//-----Array Pointers
	DNA* PopArray;											//stores the phrases in the current generation
	DNA* NextGeneration;									//stores the phrases in the next generation

	//-----Mating Pool
	std::vector<int> MatingPool;							//Stores all the potential parents to create the next generation

private:

	std::string GoalPhrase;									//stores the phrase we want to randomly generate
	DNA BestDNA;											//stores then highest scoring phrase so far, for display only
	int PopSize;											//How big the population array is
	int MutationRate;										//how often (%) a char is mutated
	int Generation;											// stores the nnumber of generations iterated throguh so far
	float GenScore = 0;										//stores the average score of the current generation
	


public:
	//-----Getters
	 int GetPopSize(){ return PopSize; };
	 int GetMutRate() { return MutationRate; };
	 std::string GetGoalPhrase() { return GoalPhrase; };

	 //-----Setters
	 void SetPopSize(int NewPopSize) { PopSize = NewPopSize; };
	 void SetMutationRate(int NewRate) { MutationRate = NewRate; };
	 void SetGoal(std::string NewGoal) { GoalPhrase = NewGoal; };

};