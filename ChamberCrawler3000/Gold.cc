#include "item.cc"
#include <string>
class Gold: public Item{
	protected:
	std::string value;
	public:
	Gold():Item(){}
	Gold(std::string type,Location loca):Item(loca,'G'){
		value=type;
	}
	int getGold(){
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
	void setLocation(Location locat){
		loc=locat;
	}
	std::string getType(){
		return value;
	}
};
