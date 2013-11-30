#include <string>
#include "location.cc"
class Item{
	protected:
	int x;
	int y;
	char symbol;
	
	public:
	Item(){
		x=0;
		y=0;
		symbol='0';
	}
	Item(int x,int y, char sym){
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
