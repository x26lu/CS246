// ChamberCrawler3000.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "floor.h"

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