#include "Character.h"

	Potion::Potion():Item(){}
	Potion::Potion(int x, int y,std::string pot):Item(0,0'P'){
		type=pot;
	}
	std::string Potion::getType(){
		return type;
	}

