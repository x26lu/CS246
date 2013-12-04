// ChamberCrawler3000.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <sstream>
#include "Floor.h"
#include "Player.h"

void printScreen(Floor *floor){
	int width = floor->getWidth();
	int height = floor->getHeight();
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			std::cout << floor->getCharAt(j, i);
		}
	}
}

std::string getAttackMsg(Character *attacker, Character *defender){
	std::string msg = "";
	std::stringstream ss;
	ss << attacker->getAtk();
	std::string str1 = ss.str();
	ss << defender->getHp();
	std::string str2 = ss.str();
	msg = msg + attacker->getSymbol() + "deals  " + str1 + "  damage  to  "
		+ defender->getSymbol() + "(" + str2 + " HP).";
	return msg;
}

int main(int argc, char *argv[])
{
	std::string filename = "default.txt";
	bool quit = false;
	std::string cmd;

	while (!quit) {
		filename = "default.txt";
		quit = false;
		bool endSession = false;
		int floorNum = 1;
		while (!endSession && floorNum <= 8)
		{
			endSession = false;
			floorNum = 1;
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
				if (cmd != "q"){ std::cout << "unsupported command. " << std::endl; }
				quit = true;
				break;
			}

			if (argc != 3 && argc != 1){
				std::cout << "unsupported command. " << std::endl;
			}
			else if (argc == 3){
				if (argv[1] == "-i"){
					filename = argv[2];
				}
				else {
					std::cout << "unsupported command. " << std::endl;
				}
			}

			std::cout << "Generating game..." << std::endl;

			Floor floor(floorNum, filename);

			//spawn floor and player
			if (filename == "default.txt"){
				floor.init();
				int tmp = floor.spawn('\\');
				floor.draw(floor.getX(tmp), floor.getY(tmp), '\\');
				tmp = floor.spawn('@');
				floor.draw(floor.getX(tmp), floor.getY(tmp), '@');
				player->setX(floor.getX(tmp));
				player->setY(floor.getY(tmp));
			}
			bool reachStair = false;

			printScreen(&floor);
			std::cout << "Race: " << player->getRace() << " Gold: " << totalGold <<
				"\t\t\tFloor: " << floorNum << std::endl;
			std::cout << "HP: " << player->getHp() << std::endl;
			std::cout << "Atk: " << player->getAtk() << std::endl;
			std::cout << "Def: " << player->getDef() << std::endl;
			std::cout << "Action: " << "Player character has spawned." << std::endl;

			while (!reachStair && !endSession && !quit)
			{
				//messag display to the player
				std::string msg = "";

				//ask for player's command until recongnize
				bool correctCmd = false;
				do{
					correctCmd = true;
					std::cin >> cmd;
					int currentX = player->getX();
					int currentY = player->getY();

					if (cmd == "q"){
						quit = true;
						break;
					}
					else if (cmd == "r"){
						endSession = true;
						break;
					}
					else if (cmd.find("u ") != std::string::npos){
						int check = 0;
						for (int r = currentX - 1; r <= currentX + 1; r++){
							for (int c = currentY; c <= currentY + 1; c++){
								if (floor.getPotion(r, c) != NULL){
									player->usePotion(*floor.getPotion(r, c));
									check = 1;
								}
							}
						}
						if (check == 0){
							msg = msg + "No Potion Nearby. ";
						}
					}
					else if (cmd.find("a ") != std::string::npos){
						int check = 0;
						for (int r = currentX - 1; r <= currentX + 1; r++){
							for (int c = currentY; c <= currentY + 1; c++){
								if (floor.getEnemy(r, c) != NULL){
									floor.getEnemy(r, c)->defend(*player);
									msg = msg + getAttackMsg(player, floor.getEnemy(r, c));
									check = 1;
								}
							}
						}
						if (check == 0){
							msg = msg + "No Enemy Nearby. ";
						}
					}
					else if (cmd == "no" || cmd == "ne" || cmd == "nw" || cmd == "se" || cmd == "so" || cmd == "sw"
						|| cmd == "ea" || cmd == "we"){
						int targetX = player->getX();
						int targetY = player->getY();

						if (cmd == "no"){
							msg = msg + "PC moves North. ";
							targetY -= 1;
						}
						else if (cmd == "ne"){
							msg = msg + "PC moves NorthEase. ";
							targetX += 1;
							targetY -= 1;
						}
						else if (cmd == "nw"){
							msg = msg + "PC moves NorthWest. ";
							targetX -= 1;
							targetY -= 1;
						}
						else if (cmd == "so"){
							msg = msg + "PC moves South. ";
							targetY += 1;
						}
						else if (cmd == "se"){
							msg = msg + "PC moves SouthEast. ";
							targetX += 1;
							targetY += 1;
						}
						else if (cmd == "sw"){
							msg = msg + "PC moves SouthWest. ";
							targetX -= 1;
							targetY += 1;
						}
						else if (cmd == "ea"){
							msg = msg + "PC moves East. ";
							targetX += 1;
						}
						else if (cmd == "we"){
							msg = msg + "PC moves West. ";
							targetX -= 1;
						}
						//if player move onto a gold, get the gold
						if (floor.getCharAt(targetX, targetY) == 'G'){
							if (floor.getGold(targetX, targetY)->getType() == "dragonHorde"){
								//check if dragon is killed
								int check = 1;
								for (int r = targetX - 1; r <= targetX + 1; r++){
									for (int c = targetY; c <= targetY + 1; c++){
										if (floor.getEnemy(r, c)->getRace() == "dragon"){
											check = 0;
										}
									}
								}
								if (check == 1){
									totalGold += floor.getGold(targetX, targetY)->getValue();
								}
								else{
									msg = msg + "Dragon is alive can not get Treasure. ";
								}
							}
							totalGold += floor.getGold(targetX, targetY)->getValue();
						}
						//if player moves onto a stair, go onto next floor
						else if (floor.getCharAt(targetX, targetY) == '\\'){
							reachStair = true;
							floorNum++;
						}

						std::string tmpMsg = floor.move(currentX, currentY, targetX, targetY, true);
						if (tmpMsg != ""){ msg = tmpMsg; }
						else{
							player->setX(targetX);
							player->setY(targetY);
						}
						//if player sees a potion, report it
						if (floor.isSymbolVisiable(player->getX(), player->getY(), 'P')){
							msg = msg + "Player sees a Potion. ";
						}
						if (floor.isSymbolVisiable(player->getX(), player->getY(), 'G')){
							msg = msg + "Player sees a Gold. ";
						}
					}
					else {
						std::cout << "unsupported command. " << std::endl;
						correctCmd = false;
					}
				}while (!correctCmd);
				// enemy's turn, if enemy can see player, attack, else move
				for (int i = 0; i < 80; i++){
					for (int j = 0; j < 25; j++){
						char currentChar = floor.getCharAt(i, j);
						if (currentChar == 'W' || currentChar == 'V' || currentChar == 'N' || currentChar == 'M' ||
							currentChar == 'D' || currentChar == 'X' || currentChar == 'T'){
							Enemy *e = floor.getEnemy(i, j);
							//if not the case enemy already moved
							if (e != NULL){
								if (e->getHp() > 0){
									if (floor.isSymbolVisiable(i, j, '@')){
										player->defend(*e);
										msg = msg + getAttackMsg(e, player);
									}
									else{
										int target = floor.getUnoccupiedRadius(i, j);
										int targetX = floor.getX(target);
										int targetY = floor.getY(target);
										std::string m = floor.move(i, j, targetX, targetY);
										if (m == ""){
											e->setX(targetX);
											e->setY(targetY);
										}
									}
								}
							}
						}
					}
				}
				if (player->getHp() <= 0){ endSession = true; }

				//print screen
				printScreen(&floor);
				std::cout << "Race: " << player->getRace() << " Gold: " << totalGold <<
					"\t\t\tFloor: " << floorNum << std::endl;
				std::cout << "HP: " << player->getHp() << std::endl;
				std::cout << "Atk: " << player->getAtk() << std::endl;
				std::cout << "Def: " << player->getDef() << std::endl;
				std::cout << "Action: " << msg << std::endl;

			}
			if (player->getRace() == "human"){
				totalGold *= 1.5;
			}
			std::cout << "Game End. Total score is " << totalGold << std::endl;
		}
	}
	return 0;
}