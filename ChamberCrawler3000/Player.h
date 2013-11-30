#include "character.cc"
#include <string.h>
#include "potion.cc"

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

	void nextFloor();
	void usePotion(Potion pot);
};

