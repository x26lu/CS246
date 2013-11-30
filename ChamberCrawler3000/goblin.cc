#include <string.h>
#include "enemy.cc"
class Goblin: public Enemy {
	
	public:
	Goblin(Location loca):Enemy(70,5,10,1,loca,'N'){
		race="goblin";
	}
	
};
