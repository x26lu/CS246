#include "Character.h"

<<<<<<< HEAD

	Potion::Potion():Item(){}
	Potion::Potion(int x, int y,std::string pot):Item(0,0'P'){
=======
class Potion : public Item{
	std::string type;
	public:
	Potion(std::string pot, Location loca):Item(loca,'P'){
		loc=loca;
>>>>>>> 3b96155defbe6b963de4457d47e1395ad633a366
		type=pot;
	}
	std::string Potion::getType(){
		return type;
	}

