// ChamberCrawler3000.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Floor.h"
#include "Player.h"

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

int main(int argc, char *argv[])
{
	std::string filename = "default.txt";
	bool quit = false;
	std::string cmd;
	while (!quit) {
		bool endSession = false;
		int floorNum = 1;
		while (!endSession && floorNum <= 8)
		{
			Player *player;
			float totalGold = 0.0;
			std::cout << "Please select your race, or enter 'q' to quit: " << std::endl;
			std::cout << "\th. human" << std::endl;
			std::cout << "\td. dwarf" << std::endl;
			std::cout << "\te. elves" << std::endl;
			std::cout << "\to. orc" << std::endl;
			std::cin >> cmd;

			if (cmd == "h"){ player = new Player("human", 0, 0); }
			else if (cmd == "d"){ player = new Player("dwarf", 0, 0); }
			else if (cmd == "e"){ player = new Player("elves", 0, 0); }
			else if (cmd == "o"){ player = new Player("orc", 0, 0); }
			else {
				if (cmd != "q"){ std::cout << "unsupported command" << std::endl; }
				quit = true;
				break;
			}

			if (argc != 3 && argc != 1){
				std::cout << "unsupported command" << std::endl;
			}
			else if (argc == 3){
				if (argv[1] == "-i"){
					filename = argv[2];
				}
				else {
					std::cout << "unsupported command" << std::endl;
				}
			}

			Floor floor(floorNum, filename);
			bool reachStair = false;
			while (!reachStair && !endSession && !quit)
			{
				printScreen(&floor);

				std::cin >> cmd;
				int currentX = player->getX();
				int currentY = player->getY();

				if (cmd == "q"){
					//TODO: theres bug with q and r, once build debug it
					
					quit = true;
					break;
				}
				else if (cmd == "r"){
					endSession = true;
					break;
				}
				else if (cmd.find("u ")){
					int check=0;
					for(int r=currentX-1;r<=currentX+1;r++){
						for(int c=currentY;c<=currentY+1;c++){
							if(floor.getPotion(r,c)!=NULL){
								player->usePotion(floor.getPotion(r,c));
								check=1;
							}
						}
					}
					if(check==0){
						std::cout << "No Potion Nearby" << std::endl;
					}
				}
				else if (cmd.find("a ")){
					int check=0;
					for(int r=currentX-1;r<=currentX+1;r++){
						for(int c=currentY;c<=currentY+1;c++){
							if(floor.getEnemy(r,c)!=NULL){
								floor.getEnemy(r,c)->defend(player);
								check=1;
							}
						}
					}
					if(check==0){
						std::cout << "No Enemy Nearby" << std::endl;
					}
				}
				else{
					int targetX = currentX;
					int targetY = currentY;

					if (cmd == "no"){ targetY -= 1; }
					else if (cmd == "ne"){
						targetX += 1;
						targetY -= 1;
					}
					else if (cmd == "nw"){
						targetX -= 1;
						targetY -= 1;
					}
					else if (cmd == "so"){ targetY += 1; }
					else if (cmd == "se"){
						targetX += 1;
						targetY += 1;
					}
					else if (cmd == "sw"){
						targetX -= 1;
						targetY += 1;
					}
					else if (cmd == "ea"){ targetX += 1; }
					else if (cmd == "we"){ targetX -= 1; }

					//if player move onto a gold, get the gold
					if (floor.getCharAt(targetX, targetY) == 'G'){
						if (floor.getGold(targetX, targetY)->getType() == "dragonHorde"){
							//TODO: check if dragon is killed
							int check=1;
							for(int r=targetX-1;r<=targetX+1;r++){
								for(int c=targetY;c<=targetY+1;c++){
									if(floor.getEnemy(r,c)->getRace()=="dragon"){
										check=0;
									}
								}
							}
							if(check==1){
								totalGold += floor.getGold(targetX, targetY)->getValue();
							}else{
								std::cout << "Dragon is alive can not get Treasure" << std::endl;
							}
						}
						totalGold += floor.getGold(targetX, targetY)->getValue();
					}
					else if (floor.getCharAt(targetX, targetY) == '\\'){
						reachStair = true;
						floorNum++;
					}
					floor.move(currentX, currentY, currentX + 1, currentY - 1);
					player->setX(currentX++);
					player->setY(currentY--);
				}
				// TODO: enemy's turn, generated one by one
				// using for loop to go through enemies
				// if within radius of player, attack, else move
				// if player.hp = 0, endSession = true
				
				
			}
		}
		if(player.getRace()=="human"){
			totalGold *=1.5;
		}
		std::cout << "Game End total score is " << totalGold<<std::endl;
	}
	return 0;
}