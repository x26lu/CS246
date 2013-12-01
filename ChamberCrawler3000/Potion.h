#include "item.h"
#include <stdlib.h>

class Potion : public Item{
	protected:
	std::string type;
	public:
	Potion();
	Potion(int x, int y,std::string pot);
	std::string getType();
	bool is

};
