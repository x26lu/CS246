#include "Enemy.h"
#include "Potion.h"
#include "Gold.h"

class Floor
{
	int floorNum;
	int width;
	int height;
	char map[2000];	//stores the map, obj.index=obj.y*width+obj.x
	Enemy* enemies;
	Potion* potions;
	Gold* golds;
	int getRand(int range, int start=0);
	int getIndex(int x, int y);
	bool isMoveable(int x, int y, bool isPlayer = true);	//check if a location is moveable
	//We require that generation happens in the following order: player character location, stairway location, potions, gold, enemies.
	void readMap(std::string filename);	//readin map from file
	void generatePotions(int potionNum=10);	//generate 10 random potions
	void generateGolds(int goldNum=20);	//generate 10 random golds
	void generateEnemies(int enemyNum=20);	//generate 20 random enemies (dragon according to golds)
	std::vector<int> chamber1;
	std::vector<int> chamber2;
	std::vector<int> chamber3;
	std::vector<int> chamber4;
	std::vector<int> chamber5;
	int stairChamber = -1;
public:
	Floor(int nFloorNum, std::string filename, int nWidth=80, int nHeight=25);
	void init();	//init at the beginning of floor
	int getWidth();
	int getHeight();
	int getX(int index);
	int getY(int index);
	int getStairChamber();
	void setStairChamber(int num);
	char getCharAt(int x, int y);	//return the symbol at (x,y)
	void draw(int x, int y, char newChar);	//draw char at given location
	void longDraw(int nX, int nY, const char* newChars);	//draw multiple chars at given location
	void release(int x, int y);	//turn symbol at target location back to default
	std::string move(int oldX, int oldY, int newX, int newY, bool isPlayer=false);	//move from old location to new location
	int spawn(char symbol=' ');	//return a random generated location
	int* getRadius(int x, int y);	//get indexes of available locations in 1 radius of current location
	int getUnoccupiedRadius(int x, int y);		//get one random unoccupied location in 1 radius
	Enemy* getEnemy(int x, int y);	//return the enemy obj at current location
	Gold* getGold(int x, int y);
	Potion* getPotion(int x, int y);
	~Floor();
};