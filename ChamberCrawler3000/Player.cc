#include "Player.h"



	Player::Player():Character(){}
	Player::Player(std::string rac, int r, int c) : Character(140, 20, 20, 0, r, c, '@'){
		race=rac;
		floor=1;
		atkmodify=0;
		defmodify=0;

		if(race=="orc"){
			hp=180;
			atk=30;
			def=25;
			gold=0;
			x=r;
			y=c;
			symbol='@';
		}else if(race=="dwarf"){
			hp=100;
			atk=20;
			def=30;
			gold=0;
			x=r;
			y=c;
			symbol='@';
		}else if (race=="elves"){
			hp=130;
			atk=30;
			def=10;
			gold=0;
			x=r;
			y=c;
			symbol='@';
		}else{
			hp=140;
			atk=20;
			def=20;
			gold=0;
			x=r;
			y=c;
			symbol='@';
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


