#include <string.h>
#include "enemy.cc"
class Dragon: public Enemy {
	
	public:
	Dragon(Location loca):Enemy(150,20,20,0,loca,'D'){
		race="dragon";
	}
	
};
