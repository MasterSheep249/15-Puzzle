#include <random>
#include <iostream>
#include "Random.h"
#include "GameBoard.h"
int main()
{
	GameBoard myBoard{};
	myBoard.randomizeBoard();
	myBoard.printBoard();
	std::cout << '\n';
	while (!(myBoard.checkOrder()))
	{
		std::cout << "Enter a command: ";
		char command{};
		std::cin >> command;
		std::cout << '\n';
		myBoard.slideTile(command);
	}
	std::cout << "You win!";
}
