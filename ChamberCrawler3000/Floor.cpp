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
}

int Floor::getRand(int range, int start){
	srand(time(NULL));
	return rand() % range + start;
}

bool Floor::isMoveable(int x, int y, bool isPlayer){
	char tmp = map[getIndex(x, y)];

	if (tmp == SymbolFloorTile){ return true; }

	if (isPlayer){
		if (tmp == SymbolPassage || SymbolDoorway || SymbolGold){ return true; }
	}
	return false;
}

void Floor::readMap(std::string filename){
	std::ifstream file;
	file.open(filename.c_str());

	file.read(map, 2000);
	if (file.eof())
	{
		// got the whole file...
		size_t bytes_really_read = file.gcount();
	}
	else if (file.fail())
	{
		std::cout << "Cannot open map file: " << filename << std::endl;
	}
	else
	{
		std::cout << filename << " is too large for a map" << std::endl;
	}

	file.close();
}

//generate random potions
void Floor::generatePotions(int potionNum){
	potions = new Potion[potionNum];
	for(int i = 0; i < potionNum; i++){
		int tmp = getRand(6);
		Potion *holder;
		int index = spawn();
		if (tmp == 0){holder = new Potion("RH", getX(index), getY(index));}
		else if (tmp == 1){ holder = new Potion("BA", getX(index), getY(index)); }
		else if (tmp == 2){ holder = new Potion("BD", getX(index), getY(index)); }
		else if (tmp == 3){ holder = new Potion("PH", getX(index), getY(index)); }
		else if (tmp == 4){ holder = new Potion("WA", getX(index), getY(index)); }
		else { holder = new Potion("WD", getX(index), getY(index)); }
		draw(holder->getX(), holder->getY(), SymbolPotion);
		potions[i] = *holder;
	}
} 

//generate random golds
void Floor::generateGolds(int goldNum){
	golds = new Gold[goldNum];
	for (int i = 0; i < goldNum; i++){
		int tmp = getRand(8);
		Gold *holder;
		int index = spawn();
		if (tmp >= 0 && tmp <= 4){ holder = new Gold("normal", getX(index), getY(index)); }
		else if (tmp >= 5 && tmp <= 6){ holder = new Gold("smallHorde", getX(index), getY(index)); }
		else { holder = new Gold("dragonHorde", getX(index), getY(index)); }
		draw(holder->getX(), holder->getY(), SymbolGold);
		golds[i] = *holder;
	}
}

//generate random enemies (with dragon according to golds)
void Floor::generateEnemies(int enemyNum){
	enemies = new Enemy[enemyNum];
	int dragonCounter = 0;

	//generate dragon according to if dragonHorde exists
	for (int i = 0; i < 20; i++){
		if (golds[i].getType() == "dragonHorde"){
			int index = getUnoccupiedRadius(golds[i].getX(), golds[i].getY());
			Enemy *tmpEnemy = new Enemy("dragon", getX(index), getY(index));
			draw(tmpEnemy->getX(), tmpEnemy->getY(), tmpEnemy->getSymbol());
			enemies[dragonCounter] = *tmpEnemy;
			dragonCounter++;
		}
	}

	for (int i = dragonCounter; i < enemyNum; i++){
		int tmp = getRand(18);
		Enemy *holder;
		int index = spawn();
		if (tmp >= 0 && tmp <= 3){ holder = new Enemy("werewolf", getX(index), getY(index)); }
		else if (tmp >= 4 && tmp <= 6){ holder = new Enemy("vampire", getX(index), getY(index)); }
		else if (tmp >= 7 && tmp <= 11){ holder = new Enemy("goblin", getX(index), getY(index)); }
		else if (tmp >= 12 && tmp <= 13){ holder = new Enemy("troll", getX(index), getY(index)); }
		else if (tmp >= 14 && tmp <= 15){ holder = new Enemy("phoenix", getX(index), getY(index)); }
		else { holder = new Enemy("merchant", getX(index), getY(index)); }
		draw(holder->getX(), holder->getY(), holder->getSymbol());
		enemies[i] = *holder;
	}
}


//************public functions************

//nWidth and nHeight are not required for this project, but they are included for further enhancement.
Floor::Floor(int nFloorNum, std::string filename, int nWidth, int nHeight) :
floorNum(nFloorNum), width(nWidth), height(nHeight)
{
	chamber1.resize(5,1);
	chamber2.resize(5,2);
	chamber3.resize(5,3);
	chamber4.resize(5,4);
	chamber5.resize(5,5);
	readMap(filename);
}

int Floor::getWidth(){
	return width;
}
int Floor::getHeight(){
	return height;
}
int Floor::getStairChamber(){
	return stairChamber;
}
void Floor::setStairChamber(int num){
	stairChamber = num;
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
	//determine the symbol at current location according to chars around
	//NOTE£º this will only work for current floorplan, need to add more cases for random generated floor
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

std::string Floor::move(int oldX, int oldY, int newX, int newY, bool isPlayer){
	if (!isMoveable(newX, newY, isPlayer)){
		return "Target location is not moveable";
	}
	char tmp = getCharAt(oldX, oldY);
	draw(newX, newY, tmp);
	release(oldX, oldY);
	return "";
}

int Floor::spawn(char symbol){
	int chamber = -1;
	int index = -1;
	if (symbol == SymbolPlayer){
		do{
			chamber = getRand(5);
		} while (chamber == getStairChamber());
	}
	else chamber = getRand(5);
	std::vector<int>* chambers = chamber1;
	if (chamber == 0){ chambers = chamber1; }
	else if(chamber == 1){ chambers = chamber2; }
	else if (chamber == 2){ chambers = chamber3; }
	else if (chamber == 3){ chambers = chamber4; }
	else if (chamber == 4){ chambers = chamber5; }

	if (symbol == SymbolStair){ setStairChamber(chamber); }
	int size = chambers.size();
	do{
		index = getRand(size);
	} while (!isMoveable(getX(chambers[index]), getY(chambers[index]), false));
	return chambers[index];
}

//return index of an unoccupied location within 1 radius, return -1 if not found
int Floor::getUnoccupiedRadius(int x, int y){
	int counter = 0;
	int holder[8];

	for (int iX = x - 1; iX <= x + 1; iX++){
		for (int iY = y - 1; iY <= y + 1; iY++){
			if (isMoveable(iX, iY)){
				holder[counter] = getIndex(iX, iY);
				counter++;
			}
		}
	}

	if (counter == 0){ return -1; }
	else { return holder[getRand(counter)]; }
}

bool Floor::isSymbolVisiable(int x, int y, char target){
	for (int iX = x - 1; iX <= x + 1; iX++){
		for (int iY = y - 1; iY <= y + 1; iY++){
			if (getCharAt(iX, iY) == target){
				return true;
			}
		}
	}
	return false;
}

Enemy* Floor::getEnemy(int x, int y){
	for (int i = 0; i < 20; i++){
		if (enemies[i].getX() == x && enemies[i].getY() == y){
			return &enemies[i];
		}
	}
	return NULL;
}

Gold* Floor::getGold(int x, int y){
	for (int i = 0; i < 20; i++){
		if (golds[i].getX() == x && golds[i].getY() == y){
			return &golds[i];
		}
	}
	return NULL;
}

Potion* Floor::getPotion(int x, int y){
	for (int i = 0; i < 10; i++){
		if (potions[i].getX() == x && potions[i].getY() == y){
			return &potions[i];
		}
	}
	return NULL;
}

Floor::~Floor()
{
	delete[] potions;
	delete[] golds;
	delete[] enemies;
}