#include "Item.h"

	Item::Item(){
		x=0;
		y=0;
		symbol='0';
	}
	Item::Item(char sym,int x,int y){
		symbol=sym;
		this->x = x;
		this->y = y;
	}
	char Item::getSymbol(){
		return symbol;
	}
	void Item::setX(int r){x=r; }
	void Item::setY(int c){y=c;}
	int Item::getX(){return x;}
	int Item::getY(){return y;}
