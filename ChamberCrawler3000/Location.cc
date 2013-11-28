
class Location{
	protected:
	int x;
	int y;
	public:
	Location(int r,int c){
		x=r;
		y=c;
	}
	Location(){
		x=-1;
		y=-1;
	}
	Location operator=(Location &b){
		x=b.x;
		y=b.y;
	}
};
