#include <string.h>
#include "enemy.cc"
class Vampire: public Enemy {
	
	public:
	Vampire(Location loca):Enemy(50,25,25,1,loca,'V'){
		race="vampire";
	}
	
};
