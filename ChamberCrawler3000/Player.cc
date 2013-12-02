#include "Player.h"



	Player::Player():Character(){}
	Player::Player(std::string rac,int x , int y){
		race=rac;
		floor=1;
		atkmodify=0;
		defmodify=0;
	
		if(race=="orc"){
			Character(180,30,25,0,x,y,'@');
		}else if(race=="dwarf"){
			Character(100,20,30,0,x,y,'@');
		}else if (race=="elves"){
			Character(140,30,10,0,x,y,'@');
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
	std::string Player::getRace(){return race;}
	void Player::usePotion(Potion pot){
		if(pot.getType()=="RH"){
			hp+=10;
			if(hp>maxhp){ hp=maxhp;}
		}else if(pot.getType()=="BA"){
			atkmodify+=5;
			atk+=5;
		}else if(pot.getType()=="BD"){
			defmodify+=5;
			def+=defmodify;
		}else if(pot.getType()=="PH"){
			hp-=10;
			if(hp<0){hp=0;/*gameend();*/}
		}else if(pot.getType()=="WA"){
			atkmodify-=5;
			atk+=atkmodify;
		}else {
			defmodify-=5;
			def+=defmodify;
		}
	}


