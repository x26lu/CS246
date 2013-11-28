#include "character.cc"
#include <string>
#include "potion.cc"

class Player: public Character{
	protected:
	std::string race;
	int floor;
	int maxhp;
	int atkmodify;
	int defmodify;
	public:
	Player(std::string rac,Location loc){
		race=rac;
		floor=1;
		atkmodfiy=0;
		defmodify=0;
	
		if(race=="orc"){

		}else if(race=="dwarf"){
	
		}else if (race=="elves"){
	
		}else{
			Character(140,20,20,0,loc,'@');
		}
	}
	void nextFloor(){
		floor++;
		atk-=atkmodify;
		atkmodify=0;
		def-=defmodify;
		defmodify=0;
	}
	void usePotion(Potion pot){
		if(pot.getType()=="RH"){
			hp+=10;
			if(hp>maxhp){ hp=maxHp;}
		}else if(pot.getType()=="BA"){
			atkmodify+=5;
			atk+=5;
		}else if(pot.getType()=="BD"){
			defmodify+=5;
			def+=defmodify;
		}else if(pot.getType()=="PH"){
			ph-=10;
			if(hp<0){hp=0;/*gameend();*/}
		}else if(pot.getType()=="WA"){
			atkmodify-=5;
			atk+=atkmodify;
		}else {
			defmodify-=5;
			def+=defmodify;
		}
	}
};

