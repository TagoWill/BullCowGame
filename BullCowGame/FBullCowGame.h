#pragma once

#include <string>
#include "EStatus.h"
#include <map>
#define TMap std::map

using FString = std::string;
using int32 = int;

//all values initialised to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:
	FBullCowGame(); //Constructor
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLenght() const;
	bool IsGameWon() const;


	EGuessStatus CheckGuessValidity(FString) const;

	void Reset();  //TODO: Make a more rich return value.
	FBullCowCount SubmitValidGuess(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHidenWord;
	bool bGameIsWon;

	// helper functions
	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};