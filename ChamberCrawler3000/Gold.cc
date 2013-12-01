#include "Gold.h"


	Gold::Gold():Item(){}
	Gold::Gold(std::string type,int x , int y):Item('G',x,y){
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

