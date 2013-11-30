#include "item.cc"
#include <stdlib.h>

class Potion : public Item{
	std::string type;
	public:
	Potion():Item(){}
	Potion(std::string pot, Location loca):Item(loca,'P'){
		loc=loca;
		type=pot;
	}
	std::string getType(){
		return type;
	}

};
