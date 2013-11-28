#include "character.cc"
#include <string>

class Enemy : public Character{
	
	string race="";

	public:
	Enemy(string races, int r, int c){
		int x=r;
		int y=c;
		race = races;
		symbol='E';
		gold=1;
		if(race=="vampire"){

		}else if(race=="werewolf"){

		}else if(race=="troll"){

		}else if(race=="goblin"){

		}else if(race==""){

		}else{
		
		}
	}

};
