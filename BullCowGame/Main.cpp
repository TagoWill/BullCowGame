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
FText GetGuess();
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

	for (int32 i = 0; i < MaxTries; i++) {
		std::cout << "Your guess was: " << GetGuess() << std::endl;
	}

	//TODO add a game summary
}

void PrintIntro() {

	std::cout << "Hello to Bulls and Cows" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetMaxTries();
	std::cout << " letter isogram I'm thinking of?" << std::endl;
	return;
}

FText GetGuess() {

	int32 CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Try ";
	std::cout << CurrentTry;
	std::cout << ". Enter your guess: ";

	FText Guess = "";
	std::getline(std::cin, Guess);



	return Guess;

}

bool AskToPlayAgain() {

	std::cout << "Do you want to play again? ";
	FText Response = "";

	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');

}