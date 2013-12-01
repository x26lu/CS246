#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include <string>
#include "potion.h"

class Player: public Character{
	protected:
	std::string race;
	int floor;
	int maxhp;
	int atkmodify;
	int defmodify;
	public:
	Player();
	Player(std::string rac,int x , int y);
	std::string getRace();
	void nextFloor();
	void usePotion(Potion pot);
};
#endif
