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

int main(int argc, char *argv[]) {
{
	//welcome msg
	// while didn't say quit game
	while (1) {
		// while end game session = false && floorNum <=8
		while (1)
		{
			int floorNum = 1;
			string floorMap = "default.txt";
			Floor newFloor(floorNum, floorMap);
			// spawn stair
			// spawn player
			// reachStair = false
			// while player didnt reach stair && endGame = false
			while (true)
			{
				// Read player's command
					// player's turn
						//can move or attack, if move
						//if on gold, get gold
						//if on stair, reachStair = true, floorNum++
					// enemy's turn, generated one by one
						//if within radius of player, attack, else move
				printScreen(&newFloor);
				// if player.hp = 0, endGame = true
			}
		}
		//calculate score
	}
	return 0;
}