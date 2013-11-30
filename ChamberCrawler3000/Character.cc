#include <string.h>
#include <math.h>

class Character{
	protected:
	int hp;
	int atk;
	int def;
	int gold;
	int x;
	int y;
	char symbol;
	public:
	Character(){
		hp=0;
		atk=0;
		def=0;
		gold=0;
		x=0;
		y=0;
		symbol='0';
	}
	Character(int h, int a, int d, int g, int r,int c,char sym){
		hp=h;
		atk=a;
		def=d;
		gold=g;
		x=r;
		y=c;
		symbol=sym;
	}
	void setX(int r){x=r;}
	void setY(int c){y=c;}
	int getX(){return x;}
	int getY(){return y;}
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

