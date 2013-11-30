#include <string.h>
#include "enemy.cc"
class Werewolf: public Enemy {
	
	public:
	Werewolf(Location loca):Enemy(120,30,5,1,loca,'W'){
		race="werewolf";
	}
	
};
