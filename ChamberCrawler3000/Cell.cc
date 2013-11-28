class Cell :Location{

	public:
	Cell(){}
	string getType(){
		if(symbol=='|'||symbol=='-'){
			return "wall";
		}else if(symbol=='.'){
			return "floor";
		}else if(symbol=='#'){
			return "passage";
		}else if(symbol=='+'){
			return "doorway";
		}
	}
	void setType(string newType){
		if(newType=="wall"){
			symbol='|';
		}else if(newType=="floor"){
			symbol='.'
		}else if(newType=="passage"){
			symbol='#'
		}else if(newType=="doorway"){
			symbol='+';
		}
	}
}