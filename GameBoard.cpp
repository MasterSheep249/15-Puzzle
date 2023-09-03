#include "GameBoard.h"
#include "random.h"
#include <iostream>
#include <algorithm>
void GameBoard::makeRows()
{
	myArray.resize(4);
	for (std::size_t index{0}; index < 4; ++index)
	{
		myArray[index].resize(4);
	}
}
GameBoard::GameBoard()
{
	int element{ 1 };
	makeRows();
	for (std::size_t index{0}; index < myArray.size(); ++index)
	{
		for (std::size_t index_2{0}; index_2 < myArray[0].size(); ++index_2)
		{
			myArray[index][index_2] = element;
			++element;
		}
	}
}
void GameBoard::randomizeBoard()
{
	std::vector<int> copy{};
	copy.resize(100);
	static int copyIndex{0};
	makeRows();
	for (std::size_t index{0}; index < myArray.size(); ++index)
	{
		for (std::size_t index_2{0}; index_2 < myArray[0].size(); ++index_2)
		{
			while (true)
			{
				int element{ Random::get(1,16) };
				auto found = std::find(copy.begin(), copy.end(), element);
				if (found == copy.end())
				{
					copy[copyIndex] = element;
					++copyIndex;
					myArray[index][index_2] = element;
					break;
				}
			}
			
		}
	}
}

void GameBoard::printBoard()
{
	//std::cout << "ji";
	for (std::size_t index{0}; index < myArray.size(); ++index)
	{
		for (std::size_t index_2{0}; index_2 < myArray[0].size(); ++index_2)
		{
			if (myArray[index][index_2] == 16)
			{
				std::cout << "   ";
			}
			else if (myArray[index][index_2] < 10)
			{
				std::cout << " " << (myArray[index][index_2]) << " ";
			}
			else
			{
				std::cout << (myArray[index][index_2]) << " ";
			}	
		}
		std::cout << '\n';
	}
}

void GameBoard::slideTile(char input)
{
	int tileX = getEmptyTileX();
	int tileY = getEmptyTileY();
	switch (input)
	{
	case 'w':
		if (getEmptyTileY() == static_cast<int>(myArray.size()) - 1)
		{
			std::cout << "INVALID COMMAND: out of bounds\n";
		}
		else
		{
			
			int temp{ myArray[getEmptyTileY() + 1][getEmptyTileX()] };
			myArray[getEmptyTileY()][getEmptyTileX()] = temp;
			myArray[tileY + 1][tileX] = 16;
			printBoard();
			std::cout << '\n';
		}
		break;
	case 's':
		if (getEmptyTileY() == 0)
		{
			std::cout << "INVALID COMMAND: out of bounds\n";
		}
		else
		{
			int temp{ myArray[getEmptyTileY() - 1][getEmptyTileX()] };
			myArray[getEmptyTileY()][getEmptyTileX()] = temp;
			myArray[tileY - 1][tileX] = 16;
			printBoard();
			std::cout << '\n';
		}
		break;
	case 'd':
		if (getEmptyTileX() == 0)
		{
			std::cout << "INVALID COMMAND: out of bounds\n";
		}
		else
		{
			int temp{ myArray[getEmptyTileY()][getEmptyTileX() - 1] };
			myArray[getEmptyTileY()][getEmptyTileX()] = temp;
			myArray[tileY][tileX - 1] = 16;
			printBoard();
			std::cout << '\n';
		}
		break;
	case 'a':
		if (getEmptyTileX() == myArray[0].size() - 1)
		{
			std::cout << "INVALID COMMAND: out of bounds\n";
		}
		else
		{
			int temp{ myArray[getEmptyTileY()][getEmptyTileX() + 1] };
			myArray[getEmptyTileY()][getEmptyTileX()] = temp;
			myArray[tileY][tileX + 1] = 16;
			printBoard();
			std::cout << '\n';
		}
		break;
	default:
		std::cout << "INVALID COMMAND: not a valid command\n\n";
	}


}

int GameBoard::getEmptyTileY()
{
	for (std::size_t index{0}; index < myArray.size(); ++index)
	{
		for (std::size_t index_2{0}; index_2 < myArray[0].size(); ++index_2)
		{
			if (myArray[index][index_2] == 16)
			{
				return index;
			}
		}
	}
	return 0;
}
int GameBoard::getEmptyTileX()
{
	int row{ getEmptyTileY() };
	for (std::size_t index{0}; index < myArray[row].size(); ++index)
	{
		if (myArray[row][index] == 16)
		{
			return index;
		}
	}
	return 0;
}

bool GameBoard::checkOrder()
{
	int number = 1;
	for (std::size_t index{0}; index < myArray.size(); ++index)
	{
		for (std::size_t index_2{0}; index_2 < myArray[0].size(); ++index_2)
		{
			if (!(myArray[index][index_2] == number))
			{
				return false;
			}
			++number;
		}
	}
	return true;
}
