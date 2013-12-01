#ifndef POTION_H
#define POTION_H
#include "item.h"
#include <stdlib.h>

class Potion : public Item{
	protected:
	std::string type;
	int rh;
	int ba;
	int bd;
	int ph;
	int wa;
	int wd;
	public:
	Potion();
	Potion(int x, int y,std::string pot);
	std::string getType();
	//void used(Potion pot);
	//bool isRevealed();

};
#endif