#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <math.h>

class Character{
	protected:
	std::string race;
	int hp;
	int atk;
	int def;
	int gold;
	int x;
	int y;
	char symbol;
	public:
	Character();
	Character(std::string race, int h, int a, int d, int g, int r,int c,char sym);
	void setRace(std::string races);
	std::string getRace();
	void setX(int r);
	void setY(int c);
	int getX();
	int getY();
	void setHp(int newHp);
	void setAtk(int newAtk);
	void setDef(int newDef);
	void setGold(int newGold);
	char getSymbol();
	int getAtk();
	int getDef();
	int getHp();
	int getGold();
	void defend(Character attacker);
	

};
#endif
