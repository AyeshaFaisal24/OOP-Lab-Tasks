# include <iostream>
# include <iomanip>
#include <string>
using namespace std;

int main () {
	string name;
	float testScores[5] ,sum =0 , average=0;
	
	cout << "Enter name:";
	getline(cin , name);
	
	cout << "Enter test scores:";
	for (int i=0 ; i<5 ; i++){
		cin >> testScores[i];
		sum += testScores[i];
	}
	
	average = sum/5;
	
	cout << "Name:" << name << endl;
	cout << "Test Scores: ";
	for (int i=0 ; i<5 ; i++){
		cout << testScores[i] << " " ;
	}
	
	cout << "\nAverage:" << fixed << setprecision(2) << average;
	
	return 0;
	
}