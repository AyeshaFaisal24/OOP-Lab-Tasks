#include <iostream>
using namespace std;

class Glass{
	public:
		int liquidLevel = 200;
		
		void drink(int millilitres){
			liquidLevel -= millilitres;
		}
		
		void refill(){
			if (liquidLevel <= 100){
				liquidLevel = 200;
				cout << "Drink Refilled!!" << endl;
			}
		}
};

int main(){
	Glass glass;
	
	int drinkDrank;
	
	do{
		cout << "1.Enter drink drank(0 to terminate):";
		cin >> drinkDrank;
		
		if (drinkDrank == 0){
			break;
		}else {
			glass.drink(drinkDrank);
			glass.refill();
		}
		
	}while(drinkDrank != 0);
	
	return 0;
}