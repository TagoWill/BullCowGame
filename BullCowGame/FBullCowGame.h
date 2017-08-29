#pragma once

#include <string>
#include "EStatus.h"

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
	EGuessStatus CheckGuessValidity(FString Guess) const;


	void Reset();  //TODO: Make a more rich return value.
	FBullCowCount SubmitGuess(FString Guess);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHidenWord;

};