#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	
	constexpr int32 DEFAULT_CURRENT_TRY = 1;
	MyCurrentTry = DEFAULT_CURRENT_TRY;

	const FString DEFAULT_HIDDEN_WORD = "planet";
	MyHidenWord = DEFAULT_HIDDEN_WORD;
	
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

// receives a VALID guess, increments tur, and returns Bull and Cow count.
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	//increment turn number
	MyCurrentTry++;
	
	//setup a return variable
	BullCowCount BullCowCount;


	//loop through all letters in the guess
		//compare letters against the hidden word

	return BullCowCount;
}
