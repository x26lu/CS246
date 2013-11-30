#include "Player.h"



	Player::Player():Character(){}
	Player::Player(std::string rac,int x , int y){
		race=rac;
		floor=1;
		atkmodfiy=0;
		defmodify=0;
	
		if(race=="orc"){

		}else if(race=="dwarf"){
	
		}else if (race=="elves"){
	
		}else{
			Character(140,20,20,0,x,y,'@');
		}
	}

	void Player::nextFloor(){
		floor++;
		atk-=atkmodify;
		atkmodify=0;
		def-=defmodify;
		defmodify=0;
	}
	void Player::usePotion(Potion pot){
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


