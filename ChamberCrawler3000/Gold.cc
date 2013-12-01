#include "Gold.h"


	Gold::Gold():Item(){}
	Gold::Gold(int x , int y,std::string type):Item(x,y,'G'){
		value=type;
	}
	int Gold::getValue(){
		if(value=="normal"){
			return 1;
		}else if(value=="smallHorde"){
			return 2;
		}else if(value=="dragonHorde"){
			return 6;
		}else{
			return 4;
		}
	}

	std::string Gold::getType(){
		return value;
	}

