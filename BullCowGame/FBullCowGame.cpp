#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLenght() const { return MyHidenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const 
{ 
	TMap<int32, int32> WordLenghtToMaxTries{ { 2, 4 }, {3, 4},{ 4, 7 },{ 5, 10 },{ 6, 16 } };
	return WordLenghtToMaxTries[MyHidenWord.length()];
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	constexpr int32 DEFAULT_CURRENT_TRY = 1;
	const FString DEFAULT_HIDDEN_WORD = GetRandomWord();

	MyCurrentTry = DEFAULT_CURRENT_TRY;
	MyHidenWord = DEFAULT_HIDDEN_WORD;
	bGameIsWon = false;
	
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{

	if (!IsIsogram(Guess)) { //If the guess isn't isogram
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess)) { //If the guess isn't all lowercase
		return EGuessStatus::Not_Lowercase;
	}
	else if (int32(Guess.length()) > GetHiddenWordLenght()) { //If the guess lenght is wrong (to long)
		return EGuessStatus::To_Long;
	}
	else if (int32(Guess.length()) < GetHiddenWordLenght()) { //If the guess lenght is wrong (to short)
		return EGuessStatus::To_Short;
	}
	else { //otherwise return ok
		return EGuessStatus::OK;
	}
	
}

// receives a VALID guess, increments tur, and returns Bull and Cow count.
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;


	//loop through all letters in the hidden word
	int32 WorldLenght = MyHidenWord.length();
	for (int32 HWindex = 0; HWindex < WorldLenght; HWindex++) { //compare letters against the guess word
		
		for (int32 GWindex = 0; GWindex < WorldLenght; GWindex++) { //if they match then
			
			if (MyHidenWord[HWindex] == Guess[GWindex]) { //Increment bulls if they're in the same place
				
				if (HWindex == GWindex) {
					BullCowCount.Bulls++;
				}
				else { //increment cows if not
					BullCowCount.Cows++;
				}
				break;
			}
		}
	}
		
	if (BullCowCount.Bulls == GetHiddenWordLenght()) {
		bGameIsWon = true;
	}

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	
	//treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }

	//Using a map to verify is the word is isogram.
	//We are adding letters to the map and if the letter is repeated we will know it and stop
	TMap<char, bool> LettersSeen;
	
	for (auto Letter : Word) {
		Letter = tolower(Letter);
		if (LettersSeen[Letter]) { // if letter existes
			return false; //we do NOT have an isogram
		}
		else {
			LettersSeen[Letter] = true; //unreal uses .add()
		}
	}

	return true; // for example in cases where /0 is entered
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for(auto Letter : Word) {
		//if not lowercae etter return false
		if (!islower(Letter)) {
			return false;
		}
	}
	return true;
}

FString FBullCowGame::GetRandomWord()
{
	srand(time(NULL));
	return WordsForTheGame[rand() % LENGHT_OF_ARRAY];
}
