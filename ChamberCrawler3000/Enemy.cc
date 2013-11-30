#include "character.cc"
#include <string>

class Enemy : public Character{

	protected:	
	std::string race;
	
	public:
	Enemy():Character(){
	
	}
	Enemy(int h, int a , int d , int g, int r , int c ,char sym):Character(h,a,d,g,r,c,sym){}
	std::string getRace(){
		return race;
	}


};
