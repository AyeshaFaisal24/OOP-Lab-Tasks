#include <iostream>
using namespace std;

class Date{
	int day;
	int month;
	int year;
	
	public:
		void setDay(int d){
			day = d;
		}
		
		void setMonth(int m){
			month = m;
		}
		
		void setYear(int y){
			year = y;
		}
		
		void displayDate(){
			cout << month << "/" << day << "/" << year;
		}
};

int main() {
	Date date;
	
	date.setDay(24);
	date.setMonth(07);
	date.setYear(2024);
	
	date.displayDate();
	
	return 0;
}