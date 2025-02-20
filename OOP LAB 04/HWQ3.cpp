#include <iostream>
#include <string>
using namespace std;

class Invoice {
private:
    string partNumber;
    string partDescription;
    int quantity;
    double pricePerItem;

public:
    Invoice(string pNumber, string pDescription, int qty, double price) 
        : partNumber(pNumber), partDescription(pDescription), quantity(qty), pricePerItem(price) {
        if (quantity < 0) {
            quantity = 0;
        }
        if (pricePerItem < 0) {
            pricePerItem = 0.0;
        }
    }
    double getInvoiceAmount() const {
        return quantity * pricePerItem;
    }

    string getPartNumber() const { 
      return partNumber;
    }
    string getPartDescription() const { 
      return partDescription; 
    }
    int getQuantity() const { 
      return quantity; 
    }
    double getPricePerItem() const { 
      return pricePerItem;
    }
};

int main() {
    Invoice invoice("1234", "Hammer", 5, 10.51);
    
    cout << "Invoice Amount: $" << invoice.getInvoiceAmount() << endl;
    
    return 0;
}
