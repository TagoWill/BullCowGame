#pragma once

#include <string>
#include "EStatus.h"
#include <map>
#include <ctime>
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
	FString MyHidenWord;
	bool bGameIsWon;
	const int32 LENGHT_OF_ARRAY = 6;
	FString WordsForTheGame[6] = { "vampire", "runes", "smoke", "foruns" , "planet", "ai"};

	// helper functions
	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
	FString GetRandomWord();
};