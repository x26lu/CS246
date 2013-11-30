#include <string.h>
#include "enemy.cc"
class Troll: public Enemy {
	
	public:
	Troll(Location loca):Enemy(120,25,15,1,loca,'T'){
		race="troll";
	}
	
};
