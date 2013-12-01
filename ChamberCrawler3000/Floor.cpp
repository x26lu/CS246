#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Floor.h"

const char SymbolPlayer = '@';
const char SymbolVerticalWall = '|';
const char SymbolHorizontalWall = '-';
const char SymbolDoorway = '+';
const char SymbolFloorTile = '.';
const char SymbolPassage = '#';
const char SymbolStair = '\\';
const char SymbolGold = 'G';
const char SymbolPotion = 'P';
const char SymbolSpace = ' '; 
const char SymbolWarewolf = NULL;

int Floor::getIndex(int x, int y){ return width * y + x; }

int Floor::getX(int index){ return index % width; }

int Floor::getY(int index){ return index / width; }

void Floor::init(){
	generatePotions();
	generateGolds();
	generateEnemies();
	//spawn stair
	//spawn player
}

int Floor::getRand(int range, int start){
	srand(time(NULL));
	return rand() % range + start;
}

bool Floor::isMoveable(int x, int y){
	char tmp = map[getIndex(x, y)];
	if (tmp == SymbolPassage || SymbolFloorTile || SymbolDoorway || SymbolGold){
		return true;
	}
	else return false;
}

void Floor::readMap(std::string filename){
	std::ifstream file;
	file.open(filename.c_str());

	if (file.fail()){
		std::cerr << "Cannot open map file" << std::endl;
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
void Floor::generatePotions(int potionNum){
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
void Floor::generateGolds(int goldNum){
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
void Floor::generateEnemies(int enemyNum){
	enemies = new Enemy[enemyNum];
	int dragonCounter = 0;

	//generate dragon according to if dragonHorde exists
	for (int i = 0; i < sizeof(golds); i++){
		if (golds[i].getType() == "dragonHorde"){
			int tmpLocation = getUnoccupiedRadius(golds[i].getX(), golds[i].getY());
			//TODO: set x and y in initializer
			Enemy *tmpEnemy = new Enemy("dragon");
			enemies[dragonCounter] = *tmpEnemy;
			enemies[dragonCounter].setX(getX(tmpLocation));
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


//************public functions************

//nWidth and nHeight are not required for this project, but they are included for further enhancement.
Floor::Floor(int nFloorNum, std::string filename, int nWidth, int nHeight) :
floorNum(nFloorNum), width(nWidth), height(nHeight)
{
	readMap(filename);
	if (filename == "default.txt"){ init(); }
}

int Floor::getWidth(){
	return width;
}

int Floor::getHeight(){
	return height;
}

char Floor::getCharAt(int x, int y){
	int index = getIndex(x, y);
	return map[index];
}

void Floor::draw(int x, int y, char newChar){
	if (x<0 || x > getWidth())
		return;
	if (y<0 || y > getHeight())
		return;

	int index = getIndex(x, y);
	map[index] = newChar;
}

void Floor::longDraw(int nX, int nY, const char* newChars){
	//TODO: not sure if needed, leave out for now.
}

void Floor::release(int x, int y){
	//determine the symbol at current location
	//TODO: this will only work for the default map, need to add more cases for special cases
	char left = getCharAt(x - 1, y);
	char right = getCharAt(x + 1, y);
	char current;

	if (left == SymbolSpace){ current = SymbolPassage; }
	else if (left == SymbolHorizontalWall){ current = SymbolDoorway; }
	else if (left == SymbolVerticalWall){ current = SymbolFloorTile; }
	else if (left == SymbolDoorway){
		if (right == SymbolFloorTile){ current = SymbolFloorTile; }
		else { current = SymbolPassage; }
	}
	else if (left == SymbolFloorTile){
		if (right == SymbolFloorTile || right == SymbolVerticalWall){ current = SymbolFloorTile; }
		else { current = SymbolDoorway; }
	}
	else if (left == SymbolPassage){
		if (right == SymbolPassage || right == SymbolSpace){ current = SymbolPassage; }
		else { current = SymbolDoorway; }
	}
	else{ current = SymbolFloorTile; }

	draw(x, y, current);
}

void Floor::move(int oldX, int oldY, int newX, int newY){
	char tmp = getCharAt(oldX, oldY);
	draw(newX, newY, tmp);
	release(oldX, oldY);
}

int* Floor::getRadius(int x, int y){
	//not sure if needed, leave out for now
}

int Floor::getUnoccupiedRadius(int x, int y){
	int tmp = 0;
	bool isMoved = false;
	while (isMoved == false)
	{
		tmp = getRand(9);
		if (tmp == 0){

		}
		if (tmp == 0){

		}
	}
	
}

Floor::~Floor()
{
	delete[] potions;
	delete[] golds;
	delete[] enemies;
}