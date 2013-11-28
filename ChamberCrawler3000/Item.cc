class Item :Location{


	public:
	Item(string type){
		if(type=="gold"){
			symbol='G';
		}else{
			symbol="P"
		}
	}
	void setType(string type){
		if(type=="gold"){
			symbol='G';
		}else{
			symbol="P"
		}
	}
	string getType(){
		if(symbol=='G'){
			return "gold";
		}else {
			return "potion"
		}
		
	}
}