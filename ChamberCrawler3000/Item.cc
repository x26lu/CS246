#include <string>
#include "location.cc"
class Item{
	protected:
	Location loc;
	char symbol;
	
	public:
	Item(Location loca, char sym){
		loc=loca;
		symbol=sym;
	}
	char getSymbol(){
		return symbol;
	}
	Location getLocation(){
		return loc;
	}
	//virtual std::string getType()=0;
	

};
