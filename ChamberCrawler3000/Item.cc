#include "Item.h"

	Item::Item(){
		x=0;
		y=0;
		symbol='0';
	}
	Item::Item(int x,int y, char sym){
		loc=loca;
		symbol=sym;
	}
	Item::char getSymbol(){
		return symbol;
	}
	void Item::setX(int r){x=r;}
	void Item::setY(int c){y=c;}
	int Item::getX(){return x;}
	int Item::getY(){return y;}
