// ChamberCrawler3000.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "floor.h"

const char PlayerSymbol = 0x01;    // ASCII Man
const char VerticalWallSymbol = 0xBA;    // Vertical wall piece
const char HorizontalWallSymbol = 0xCD;    // Horizontal wall piece
const char FloorTileSymbol = 0x2E;    // Floor tile 
const char WarewolfSymbol = 'W';    // ASCII Warewolf

using namespace std;

void printScreen(Floor *floor){
	int width = floor->getWidth();
	int height = floor->getHeight();
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			cout << floor->getCharAt(j, i);
		}
		cout << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	while (1)
	{
		string floorMap = "default.txt";
		int floorNum = 1;
		Floor newFloor(floorNum, floorMap);
		// Read player's command
		//    Update dungeon
		//    Draw dungeon
		printScreen(&newFloor);
		break;
	}

	return 0;
}