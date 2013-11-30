#pragma once

#include "Location.cc"
#include "Enemy.cc"
#include "Potion.cc"
#include "Gold.cc"

class Floor
{
	int floorNum;
	int width;
	int height;
	char* map;	//stores the map, obj.index=obj.y*width+obj.x
	Enemy* enemies;
	Potion* potions;
	Gold* golds;

	int getRand(int range, int start = 0);
	int getIndex(int x, int y);
	//We require that generation happens in the following order: player character location, stairway location, potions, gold, enemies.
	void init();	//init at the beginning of floor
	void readMap(string filename);	//readin map from file
	void generatePotions(int potionNum = 10);	//generate 10 random potions
	void generateGolds(int goldNum = 10);	//generate 10 random golds
	void generateEnemies(int enemyNum = 20);	//generate 20 random enemies (dragon according to golds)
public:
	Floor(int nFloorNum, string filename, int nWidth = 79, int nHight = 25);
	void draw(int x, int y, char newChar);	//draw char at given location
	void longDraw(int nX, int nY, const char* newChars);	//draw multiple chars at given location
	void release(int x, int y);	//turn symbol at target location back to default
	void move(int oldX, int oldY, int newX, int newY);	//move from old location to new location
	int* getRadius(int x, int y);	//get indexes of available locations in 1 radius of current location
	int getUnoccupiedRadius(int x, int y);		//get one random unoccupied location in 1 radius
	~Floor();
};