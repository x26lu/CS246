#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include <string>

class Enemy : public Character{

	protected:	
		std::string race;
		int hostile;
	public:
	Enemy();
	Enemy(std::string races,int x ,int y);
	std::string getRace();
	void beHostile();
	bool isHostile();
};
#endif