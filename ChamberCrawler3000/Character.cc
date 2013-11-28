#include <string.h>
#include <math.h>
#include "location.cc"
class Character{
	protected:
	int hp;
	int atk;
	int def;
	int gold;
	Location loc;
	char symbol;
	public:
	Character(int h, int a, int d, int g, Location l,char sym){
		hp=h;
		atk=a;
		def=d;
		gold=g;
		loc = l;
		symbol=sym;
	}
	Location getLocation(){return loc;}
	void setHp(int newHp){hp=newHp;}
	void setAtk(int newAtk){atk=newAtk;}
	void setDef(int newDef){def=newDef;}
	void setGold(int newGold){gold=newGold;}
	char getSymbol(){return symbol;}
	int getAtk(){return atk;}
	int getDef(){return def;}
	int getHp(){return hp;}
	int defend(Character attacker){
		hp-=ceil((100/(100+def))*attacker.getAtk());
	}
	

};

