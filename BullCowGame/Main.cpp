/*
* This is the main file and controls the user console
* Is the view of the user.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"


using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();


FBullCowGame BCGame;

int main()
{
	bool bWantsToPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bWantsToPlayAgain = AskToPlayAgain();
	} while (bWantsToPlayAgain);
	
	return 0;
}

void PlayGame()
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();
	FText Guess = "";
	FBullCowCount BullCowCount;


	//loop for the number of turns asking for guesses
	for (int32 i = 0; i < MaxTries; i++) { //TODO a while...
		Guess = GetValidGuess();
	
		//submit valid guess to the game
		BullCowCount = BCGame.SubmitValidGuess(Guess);
		//print number of bulls and cows
	
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

	}

	//TODO add a game summary
}

void PrintIntro() {

	// TODO change to different words
	std::cout << "Hello to Bulls and Cows\n\n" << std::endl;
	std::cout << "The word as " << BCGame.GetHiddenWordLenght() << " letters\n";
	std::cout << "Can you guess in " << BCGame.GetMaxTries();
	std::cout << " tries the isogram I'm thinking of?" << std::endl;
	return;
}

//loop until you find a valid guess
FText GetValidGuess() {

	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";

	do {
		int32 CurrentTry = BCGame.GetCurrentTry();

		std::cout << "Try ";
		std::cout << CurrentTry;
		std::cout << ". Enter your guess: ";

		std::getline(std::cin, Guess);

		// TODO Se if you can put this in the object
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "The word you wrote isnt an isogram\n";

			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "The word you wrote is not in lowercase\n";

			break;
		case EGuessStatus::To_Long:
			std::cout << "The word you wrote is to long\n";
			std::cout << "Please insert a " << BCGame.GetHiddenWordLenght();
			std::cout << " letter word\n";

			break;
		case EGuessStatus::To_Short:
			std::cout << "The word you wrote is to short\n";
			std::cout << "Please insert a " << BCGame.GetHiddenWordLenght();
			std::cout << " letter word\n";

			break;
		default:
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
	return Guess;
}

bool AskToPlayAgain() {

	std::cout << "Do you want to play again? ";
	FText Response = "";

	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');

}