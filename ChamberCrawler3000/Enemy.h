#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include <string>

class Enemy : public Character{

	protected:	
		int hostile = 1;
	public:
	Enemy();
	Enemy(std::string races,int x ,int y);
	void beHostile();
	bool isHostile();
};
#endif