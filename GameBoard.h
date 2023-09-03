#pragma once
#include <vector>
class GameBoard
{
	std::vector<std::vector<int>> myArray{{}};
	
public:
	GameBoard();
	bool checkOrder();
	int getEmptyTileX();
	int getEmptyTileY();
	void slideTile(char input);
	void makeRows();
	void randomizeBoard();
	void printBoard();
};
