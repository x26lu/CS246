#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item{
	protected:
	int x;
	int y;
	char symbol;
	
	public:
	Item();
	Item( char sym,int x,int y);
	char getSymbol();
	void setX(int r);
	void setY(int c);
	int getX();
	int getY();

};
#endif