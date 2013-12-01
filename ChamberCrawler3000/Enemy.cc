#include "Enemy.h"


	Enemy::Enemy():Character(){	
	}
	Enemy::Enemy(std::string races,int x ,int y){
		if(races=="vampire"){
			Character(50,25,25,1,x,y,'V');
		}else if(races=="werewolf"){
			Character(120,30,5,1,x,y,'W');
		}else if(races=="dragon"){
			Character(150,20,20,0,x,y,'D');
		}else if(races=="goblin"){
			Character(70,5,10,1,x,y,'N');
		}else if(races=="merchant"){
			Character(30,70,5,0,x,y,'M');
			hostile=0;
		}else if(races=="phoenix"){
			Character(50,35,20,1,x,y,'X');
		}else {
			Character(120,25,15,1,x,y,'T');
		}
	}
	void Enemy::beHostile(){
		hostile=1;
	}
	bool Enemy::isHostile(){
		return hostile==1;
	}

