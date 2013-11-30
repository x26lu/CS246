#include <string.h>
#include "enemy.cc"
class Merchant: public Enemy {
	protected:
	static int hostile;
	public:
	Merchant(Location loca):Enemy(30,70,5,0,loca,'M'){
		race="merchant";
		hostile=0;
	}
	void beHostile(){
		hostile=1;
	}
	bool isHostile(){
		return hostile==1;
	}
	
};
