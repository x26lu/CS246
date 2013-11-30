#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stdafx.h"
#include "Floor.h"
using namespace std;

int Floor::getIndex(int x, int y){
	return width * y + x;
}

int Floor::getRand(int range, int start = 0){
	srand(time(NULL));
	rand() % range + start;
}

void Floor::init(){
	generatePotions();
	generateGolds();
	generateEnemies();

}

void Floor::readMap(string filename){
	ifstream file;
	file.open(filename.c_str());

	if (file.fail()){
		cerr << "Cannot open map file" << endl;
	}
	else{
		for (int j = 0; j < width; j++)
		{
			for (int i = 0; i < height; i++)
			{
				int index = getIndex(j, i);
				//TODO: check for numbers that represent items and modify them
				if (!(file >> map[index]))
				{
					std::cerr << "error while reading file";
					break;
				}
			}
			if (!file) break;
		}
	}
	file.close();
}

//generate random potions
void Floor::generatePotions(int potionNum = 10){
	potions = new Potion[potionNum];
	for(int i = 0; i < potionNum; i++){
		int tmp = getRand(6);
		Potion *holder;
		if (tmp == 0){holder = new Potion("RH");}
		else if (tmp == 1){ holder = new Potion("BA"); }
		else if (tmp == 2){ holder = new Potion("BD"); }
		else if (tmp == 3){ holder = new Potion("PH"); }
		else if (tmp == 4){ holder = new Potion("WA"); }
		else { holder = new Potion("WD"); }
		potions[i] = *holder;
	}
} 

//generate random golds
void Floor::generateGolds(int goldNum = 10){
	golds = new Gold[goldNum];
	for (int i = 0; i < goldNum; i++){
		int tmp = getRand(8);
		Gold *holder;
		if (tmp >= 0 && tmp <= 4){ holder = new Gold("normal"); }
		else if (tmp >= 5 && tmp <= 6){ holder = new Gold("smallHorde"); }
		else { holder = new Gold("dragonHorde"); }
		golds[i] = *holder;
	}
}

//generate random enemies (with dragon according to golds)
void Floor::generateEnemies(int enemyNum = 20){
	enemies = new Enemy[enemyNum];
	int dragonCounter = 0;

	//generate dragon according to if dragonHorde exists
	for (int i = 0; i < sizeof(golds); i++){
		if (golds[i].getType() == "dragonHorde"){
			Enemy *tmpEnemy = new Enemy("dragon");
			enemies[dragonCounter] = *tmpEnemy;
			Location tmpLocation = getUnoccupiedLocation(golds[i].getLocation());
			enemies[dragonCounter].getLocation() = tmpLocation;
			dragonCounter++;
		}
	}

	for (int i = dragonCounter; i < enemyNum; i++){
		int tmp = getRand(18);
		Enemy *holder;
		if (tmp >= 0 && tmp <= 3){ holder = new Enemy("werewolf"); }
		else if (tmp >= 4 && tmp <= 6){ holder = new Enemy("vampire"); }
		else if (tmp >= 7 && tmp <= 11){ holder = new Enemy("goblin"); }
		else if (tmp >= 12 && tmp <= 13){ holder = new Enemy("troll"); }
		else if (tmp >= 14 && tmp <= 15){ holder = new Enemy("phoenix"); }
		else { holder = new Enemy("merchant"); }
		enemies[i] = *holder;
	}
}

Floor::Floor(int nFloorNum, string filename, int nWidth = 79, int nHight = 25) :
floorNum(nFloorNum), width(nWidth), height(nHight)
{
	readMap(filename);
}

void Floor::draw(int x, int y, char newChar){
	int index = getIndex(x, y);
	map[index] = newChar;
}

void Floor::longDraw(int nX, int nY, const char* newChars){

}

Location* Floor::getRadius(Location currentLocation){

}

Floor::~Floor()
{
	delete[] potions;
	delete[] golds;
	delete[] enemies;
}