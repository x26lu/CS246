#pragma once

#include "Location.cc"
#include "Enemy.cc"
#include "Potion.cc"
#include "Gold.cc"

class Floor
{
	int floorNum;
	char map[25][79];
	Enemy* enemies;
	Potion* potions;
	Gold* golds;
public:
	//constructor will call readMap and spawn which calls 3 generate functions
	Floor(int floorNum, string filename);
	void readMap(string filename);	//readin map from file
	void generatePotions(int potionNum = 10);	//generate 10 random potions
	void generateGolds(int goldNum = 10);	//generate 10 random golds
	void generateEnemies(int enemyNum = 20);	//generate 20 random enemies (dragon according to golds)
	//We require that generation happens in the following order: player character location, stairway location, potions, gold, enemies.
	void spawn();	//spawn at the beginning of floor
	void release(Location location);	//turn symbol at target location back to default
	Location* getRadius(Location currentLocation);
	Location getUnoccupiedLocation(Location currentLocation);
	~Floor();
};