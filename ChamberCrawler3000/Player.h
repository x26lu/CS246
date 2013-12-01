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

	void nextFloor();
	void usePotion(Potion pot);
};

