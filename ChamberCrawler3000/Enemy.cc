#include "character.cc"
#include <string>

class Enemy : public Character{

	protected:	
	std::string race;
	
	public:
	Enemy(int h,int a,int d,int g,Location l,char sym):Character(h,a,d,g,l,sym){}
	std::string getRace(){
		return race;
	}


};
