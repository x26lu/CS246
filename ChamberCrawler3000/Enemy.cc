#include "Enemy.h"


	Enemy::Enemy():Character(){	
	}
	Enemy::Enemy(std::string races, int r, int c) : Character(120, 30, 5, 1, x, y, 'W'){
		race = races;
		if(races=="vampire"){
			hp=50;
			atk=25;
			def=25;
			gold=1;
			x=r;
			y=c;
			symbol='V';
		}else if(races=="werewolf"){
			hp=120;
			atk=30;
			def=5;
			gold=1;
			x=r;
			y=c;
			symbol='W';
		}else if(races=="dragon"){
			hp=150;
			atk=20;
			def=20;
			gold=0;
			x=r;
			y=c;
			symbol='D';
		}else if(races=="goblin"){
			hp=70;
			atk=5;
			def=10;
			gold=1;
			x=r;
			y=c;
			symbol='N';
		}else if(races=="merchant"){
			hp=30;
			atk=70;
			def=5;
			gold=0;
			x=r;
			y=c;
			symbol='M';
			
			hostile=0;
		}else if(races=="phoenix"){
			hp=50;
			atk=35;
			def=20;
			gold=1;
			x=r;
			y=c;
			symbol='X';
			
		}else {
			hp=120;
			atk=25;
			def=15;
			gold=1;
			x=r;
			y=c;
			symbol='T';
		}
	}
	std::string Enemy::getRace(){
		return race;
	}
	void Enemy::beHostile(){
		hostile=1;
	}
	bool Enemy::isHostile(){
		return hostile==1;
	}

