#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string movieName;
    float adultTicketPrice, childTicketPrice , donationPercentage;
    int numAdultTicketsSold, numChildTicketsSold;
    
    cout << "Enter movie name: ";
    getline(cin, movieName); 

    cout << "Enter adult ticket price: $";
    cin >> adultTicketPrice;
    
    cout << "Enter child ticket price: $";
    cin >> childTicketPrice;
    
    cout << "Enter number of adult tickets sold: ";
    cin >> numAdultTicketsSold;
    
    cout << "Enter number of child tickets sold: ";
    cin >> numChildTicketsSold;
    
    cout << "Enter donation percentage: ";
    cin >> donationPercentage;
    
    float grossAmount = (numAdultTicketsSold * adultTicketPrice) + (numChildTicketsSold * childTicketPrice);
    float amountDonated = grossAmount * (donationPercentage / 100);
    float netSale = grossAmount - amountDonated;
    
    cout << fixed << setprecision(2);
    
    cout << "\n_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n";
    cout << "Movie Name: " << left << setw(40) << movieName << endl;
    cout << "Number of Tickets Sold: " << right << setw(10) << (numAdultTicketsSold + numChildTicketsSold) << endl;
    cout << "Gross Amount: $" << right << setw(12) << grossAmount << endl;
    cout << "Percentage of Gross Amount Donated: " << right << setw(8) << donationPercentage << "%" << endl;
    cout << "Amount Donated: $" << right << setw(12) << amountDonated << endl;
    cout << "Net Sale: $" << right << setw(15) << netSale << endl;
    
    return 0;
}
