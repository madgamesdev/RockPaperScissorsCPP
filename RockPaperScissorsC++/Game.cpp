#include <iostream>
#include <algorithm>
#include "Game.h"

using namespace std;

void Game::Initialize() {
    //   static_cast<unsigned int> is to make the compiler shut up
    srand(static_cast<unsigned int>(time(0))); // rand seed

    gameRunning = true;
    while (gameRunning) {
        Run();
    }
}

void Game::Run() {
    int randomNumber = (rand() % maxNumber) + 1;

    cout << "Rock Paper Scissors!\n" << "Choose!\n";
    cin >> userInput;

    transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

    if (userInput == "exit") { 
        gameRunning = false; 
        return;
    }

    int result = 0;
    if (randomNumber == 1) {
        cout << "The computer chose rock.\n";
        if (userInput == "paper") { result = 1; }
        else if (userInput == "rock") { result = 2; }
    } else if (randomNumber == 2) {
        cout << "The computer chose paper.\n";
        if (userInput == "scissors") { result = 1; }
        else if (userInput == "paper") { result = 2; }
    } else if (randomNumber == 3) {
        cout << "The computer chose scissors.\n";
        if (userInput == "rock") { result = 1; }
        else if (userInput == "scissors") { result = 2; }
    }

    cout << "You chose: " << userInput << "\n";

    EasterEggCheck();

    if (result == 1) {
        cout << "You won!\n\n";
    } else if (result == 2) {
        cout << "Tie!\n\n";
    } else {
        cout << "You lost!\n\n";
    }

    cout << string(40, '=') << "\n\n";
}

void Game::EasterEggCheck() {
    if (userInput == "ttt" || userInput == "triplet" || userInput == "tung tung tung sahur") { 
        cout << "\nBoy is that a Triple T reference -- Son I'm crine\n\n"; 
    } else if (userInput == "67") { 
        cout << "\n67 so tuff boiiiii\n\n"; 
    }
}