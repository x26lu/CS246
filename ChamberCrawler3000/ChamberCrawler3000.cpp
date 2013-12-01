// ChamberCrawler3000.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "floor.h"

void printScreen(Floor *floor){
	int width = floor->getWidth();
	int height = floor->getHeight();
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			std::cout << floor->getCharAt(j, i);
		}
		std::cout << std::endl;
	}
}

int main(int argc, char *argv[]) {
{
	//welcome msg
	std::string filename = "default.txt";
	bool quit = false;
	while (!quit) {
		bool endSession = false;
		int floorNum = 1;
		while (!endSession && floorNum <= 8)
		{
			if (argc != 3 && argc != 1){
				std::cerr << "unsupported command";
			}
			else if (argc == 3){
				if (argv[1] == "-i"){
					filename = argv[2];
				}
				else {
					std::cerr << "unsupported command";
				}
			}

			Floor newFloor(floorNum, filename);
			bool reachStair = false;
			while (!reachStair && !endSession)
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