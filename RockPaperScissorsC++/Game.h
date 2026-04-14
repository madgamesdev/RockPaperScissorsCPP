#ifndef GAME_H
#define GAME_H

#include <string>

using namespace std;

class Game {
private:
	bool gameRunning = false;

	int maxNumber = 3;
	string userInput;

	void Run();
	void EasterEggCheck();
public:
	void Initialize();
};

#endif