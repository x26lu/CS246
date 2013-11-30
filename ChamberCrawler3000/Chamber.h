#pragma once
class Chamber
{
private:
	static int chamberNum;
	int startX;
	int startY;
	int lengthX;
	int lengthY;

public:
	Chamber(int n_startX, int n_startY, int n_lengthX, int n_lengthY) :
		startX(n_startX), startY(n_startY), lengthX(n_lengthX), lengthY(n_lengthY){};
	~Chamber();
};