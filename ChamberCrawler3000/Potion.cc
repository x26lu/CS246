#include "Potion.h"

Potion::Potion():Item(){	
	rh=0;
	ba=0;
	bd=0;
	ph=0;
	wa=0;
	wd=0;
}
Potion::Potion(int x, int y,std::string pot):Item(0,0,'P'){
	type=pot;
	rh=0;
	ba=0;
	bd=0;
	ph=0;
	wa=0;
	wd=0;
}
std::string Potion::getType(){
	return type;
}/*
void Potion::used(Potion &pot){
	if(pot.getType=="RH"){
		rh=1;
	}else if(pot.getType=="BA"){
		ba=1;
	}else if(pot.getType=="BD"){
		bd=1;
	}else if(pot.getType=="ph"){
		ph=1;
	}else if(pot.getType=="wa"){
		wa=1;
	}else {
		wd=1;
	}
}

bool Potion::isRevealed(){
	if(type=="RH" ){
		return rh==1;
	}else if(type=="BA"){
		return ba==1;
	}else if(type=="BD"){
		return bd==1;
	}else if(type=="ph"){
		return ph==1;
	}else if(type=="wa"){
		return wa==1;
	}else {
		return wd==1;
	}
}
*/
