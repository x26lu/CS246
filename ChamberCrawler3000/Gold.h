#ifndef GOLD_H
#define GOLD_H

#include "item.h"
#include <string>

class Gold: public Item{
	protected:
	std::string value;
	public:
	Gold();
	Gold(int x, int y,std::string type);
	int getValue();
	
	std::string getType();
};
#endif