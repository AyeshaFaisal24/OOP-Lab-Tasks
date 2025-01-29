#include <iostream>
#include <iomanip>
using namespace std;

int main () {
	float weightinkg , weightinPounds;
	
	cout << "Enter weight in kg:" ;
	cin >> weightinkg;
	
	weightinPounds = weightinkg * 2.2;
	
	cout << "Weight in kilograms:" << fixed << setprecision(2)<< weightinkg << endl;
	cout << "Weight in pounds:" << fixed << setprecision(2) << weightinPounds << endl;
	
	return 0;
	
}