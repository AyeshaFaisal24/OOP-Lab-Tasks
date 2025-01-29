#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int customerID , unitsConsumed;
	string customerName;
	float amountCharges=0 , surchargeAmount=0 , netAmount=0 ;
	
	cout << "Enter Customer ID: ";
	cin >> customerID;
	cout << "Enter Customer name: ";
	cin >> customerName;
	cout << "Enter units consumed: ";
	cin >> unitsConsumed;
	
	if (unitsConsumed>0 && unitsConsumed<200){
		amountCharges = unitsConsumed * 16.20;
	}else if (unitsConsumed>199 && unitsConsumed<300){
		amountCharges = unitsConsumed * 20.10;
	}else if (unitsConsumed>299 && unitsConsumed<500){
		amountCharges = unitsConsumed * 27.10;
	}else {
		amountCharges = unitsConsumed * 35.90;
	}
	
	if (amountCharges>18000){
		surchargeAmount = amountCharges * 0.15;
	}else {
		surchargeAmount = 0;
	}
	
	netAmount = surchargeAmount + amountCharges;
	
	cout << "Customer ID:" << customerID << endl;
	cout << "Customer name:" << customerName << endl;
	cout << "Units consumed:" << unitsConsumed << endl;
	cout << "Amount Charges: Rs. " << fixed << setprecision(2) << amountCharges << endl;
	cout << "Surcharge Amount:Rs." << surchargeAmount << endl;
	cout << "Net Amount Paid by the Customer:Rs." << netAmount << endl;
	
	return 0;
	
}