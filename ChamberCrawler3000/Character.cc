#include "Character.h"


	Character::Character(){
		hp=0;
		atk=0;
		def=0;
		gold=0;
		x=0;
		y=0;
		symbol='0';
	}
	Character::Character(std::string races, int h, int a, int d, int g, int r, int c, char sym){
		race = races;
		hp=h;
		atk=a;
		def=d;
		gold=g;
		x=r;
		y=c;
		symbol=sym;
	}
	void Character::setRace(std::string races){ race = races; }
	std::string Character::getRace(){return race; }
	void Character::setX(int r){x=r;}
	void Character::setY(int c){y=c;}
	int Character::getX(){return x;}
	int Character::getY(){return y;}
	void Character::setHp(int newHp){hp=newHp;}
	void Character::setAtk(int newAtk){atk=newAtk;}
	void Character::setDef(int newDef){def=newDef;}
	void Character::setGold(int newGold){gold=newGold;}
	char Character::getSymbol(){return symbol;}
	int Character::getAtk(){return atk;}
	int Character::getDef(){return def;}
	int Character::getHp(){return hp;}
	int Character::getGold(){return gold;}
	void Character::defend(Character attacker){
		hp-=ceil((100/(100+def))*attacker.getAtk());
	}
	



