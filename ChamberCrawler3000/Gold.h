#include "item.cc"
#include <string>
class Gold: public Item{
	protected:
	std::string value;
	public:
	Gold();
	Gold(int x, int y,std::string type);
	int getGold();
	void setLocation(Location locat);
	std::string getType();
};
