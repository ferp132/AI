#pragma once
//				Media Design School
//Author:		Louis Cresswell
//email:		louiscresswell33@gmail.com
//Submitted:	16/10/2018
//For Program:	Genetic Algorithm
#include <string>

class DNA
{
public:
	DNA();
	~DNA();


	
private:
	std::string Phrase;
	int Score;

public:
	std::string GetPhrase() { return Phrase; };
	int GetScore() { return Score; };

	void ResizePhrase(int NewSize) { Phrase.resize(NewSize, ' '); };
	void SetPhraseAt(char NewChar, int Pos) { Phrase.at(Pos) = NewChar; };
	void SetPhrase(std::string NewPhrase) { Phrase = NewPhrase; };
	void SetScore(int NewScore) { Score = NewScore; };
	void IncrementScore() { Score++; };
};