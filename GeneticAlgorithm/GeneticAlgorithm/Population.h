#pragma once
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <Windows.h>
#include "DNA.h"

class Population
{
public:
	//-----Con/Destructors
	Population(int Size, int MutRate, std::string Goal);	// Begin with a population size, Mutation rate & Goal Phrase
	~Population();

	//-----Algorithm
	void Init();
	void ProcessGenAlg();
	void CalcFitness();
	void Select();
	void Breed(int First, int Second, int Pos);
	void Draw();

	DNA* PopArray;
	DNA* NextGeneration;

	std::vector<int> MatingPool;

private:

	std::string GoalPhrase;
	DNA BestDNA;
	int PopSize;
	int MutationRate;
	int Generation;
	


public:
	//-----Getters
	 int GetPopSize(){ return PopSize; };
	 int GetMutRate() { return MutationRate; };
	 std::string GetGoalPhrase() { return GoalPhrase; };

	 void SetPopSize(int NewPopSize) { PopSize = NewPopSize; };
	 void SetMutationRate(int NewRate) { MutationRate = NewRate; };
	 void SetGoal(std::string NewGoal) { GoalPhrase = NewGoal; };

};