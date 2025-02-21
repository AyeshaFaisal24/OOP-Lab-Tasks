#include <iostream>
#include <vector>
using namespace std;

class Car{
	public:
		string name;
		int ID;
		
		Car(string n , int id){
			name=n;
			ID=id;
		}
class Garage{
	vector<Car*>car;
	
	public:
		void parkCar(Car* car1) {
        	car.push_back(car1);  
    	}
    	
    	void listCars(){
			for (int i=0 ; i<car.size() ; i++){
				cout << "Name:" << car[i]->name << endl << "ID:" << car[i]->ID << endl;
			}
		}
};
  
int main(){
	Car car1("Swift" , 190);
	Car car2("Yaris" , 897);
	Car car3("Grande" , 678);
	Garage garage;
	
	garage.parkCar(&car1);
	garage.parkCar(&car2);
	garage.parkCar(&car3);
	
	garage.listCars();
	
	return 0;
}