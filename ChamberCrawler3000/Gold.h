#ifndef GOLD_H
#define GOLD_H

#include "item.h"
#include <string>
#include "enemy.h"
class Gold: public Item{
	protected:
	std::string value;
	Enemy keeper;
	public:
	Gold();
	Gold(std::string type,int x, int y);
	Gold(std::string type,int x, int y, Enemy &dragon);
	int getValue();
	
	std::string getType();
	bool isDragonkilled();
};

#endif