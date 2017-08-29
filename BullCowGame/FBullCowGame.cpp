#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLenght() const { return MyHidenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	constexpr int32 DEFAULT_CURRENT_TRY = 1;
	const FString DEFAULT_HIDDEN_WORD = "planet";


	MyMaxTries = MAX_TRIES;
	MyCurrentTry = DEFAULT_CURRENT_TRY;
	MyHidenWord = DEFAULT_HIDDEN_WORD;
	
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString) const
{
	return false;
}

// receives a VALID guess, increments tur, and returns Bull and Cow count.
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//increment turn number
	MyCurrentTry++;
	
	//setup a return variable
	FBullCowCount BullCowCount;


	//loop through all letters in the guess
	int32 HiddenWorldLenght = MyHidenWord.length();
	for (int32 i = 0; i < HiddenWorldLenght; i++) {
		//compare letters against the hidden word
		for (int32 j = 0; j < HiddenWorldLenght; j++) {
			//if they match then
			if (MyHidenWord[i] == Guess[j]) {
				//Increment bulls if they're in the same place
				if (i == j) {
					BullCowCount.Bulls++;
				}
				else {
					//increment cows if not
					BullCowCount.Cows++;
				}
				break;
			}
		}
	}
		

	return BullCowCount;
}
