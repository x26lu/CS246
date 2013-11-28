class Location {
	int x;
	int y;
	char symbol;
	public:
	Location(int r, int c, char sym){
		x=r;
		y=c;
		symbol=sym;
	}
	getSymbol(){
		return symbol;
	}
	setSymbol(char newSymbol){
		symbol=newSymbol;
	}
}