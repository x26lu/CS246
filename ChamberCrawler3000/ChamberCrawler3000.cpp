// ChamberCrawler3000.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "stdafx.h"
#include "floor.h"

char PlayerSymbol = 0x01;    // ASCII Man
char DuckASCII = 0x44;    // ASCII Duck
char VerticalWallSymbol = 0xBA;    // Vertical wall piece
char HorizontalWallSymbol = 0xCD;    // Horizontal wall piece
char TopRightCornerSymbol = 0xBB;    // Top right wall piece
char TopLeftCornerSymbol = 0xC9;    // Top left wall piece
char BotLeftCornerSymbol = 0xC8;    // Bottom right wall piece
char BotRightCornerSymbol = 0xBC;    // Bottom left wall piece
char FloorTileSymbol = 0x2E;    // Floor tile 


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