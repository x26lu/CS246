#include "Gold.h"


	Gold::Gold():Item(){}
	Gold::Gold(std::string type,int x , int y):Item('G',x,y){
		value=type;
	}
	Gold::Gold(std::string type,int x , int y, Enemy &dragon):Item('G',x,y){
		value=type;
		keeper=dragon;
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
	bool Gold::isDragonkilled(){
		return keeper.getHp()<=0;
	}
	std::string Gold::getType(){
		return value;
	}

