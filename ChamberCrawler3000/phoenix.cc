#include <string.h>
#include "enemy.cc"
class Phoenix: public Enemy {
	
	public:
	Phoenix(Location loca):Enemy(50,35,20,1,loca,'X'){
		race="phoenix";
	}
	
};
