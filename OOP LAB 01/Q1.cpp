#include<iostream>
using namespace std;

int main (int argc , char *argv[]) {
	float max=0 , sec_max=0 ;
	
	for (int i=1 ; i<argc ; i++) {
		if (stof(argv[i]) > max) {
			sec_max = max ;
			max = stof(argv[i]);
		}
		
		if (stof(argv[i]) !=  max && stof(argv[i]) > sec_max){
		 	sec_max = stof(argv[i]);
		 }
	}
	
	cout << "Second Highest:" << sec_max;
	
	return 0;
}
