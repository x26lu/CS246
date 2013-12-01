#include "character.h"
#include <string>

class Enemy : public Character{

	protected:	
	static int hostile;
	std::string race;
	
	public:
	Enemy();
	Enemy(std::string races,int x ,int y);
	void beHostile();
	bool isHostile();
};
