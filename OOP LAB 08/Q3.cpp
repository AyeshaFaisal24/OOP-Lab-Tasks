#include <iostream>
#include <string>
#include <map>
using namespace std;

class Currency {
    protected:
        double amount;
        string currencyCode;
        string currencySymbol;
        double exchangeRate; 

    public:
        Currency(double amt, string code, string symbol, double rate)
            : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

        virtual double convertToBase() {
            return amount * exchangeRate;
        }

        virtual double convertTo(string targetCode, const map<string, double>& rates) {
            if (rates.find(targetCode) == rates.end()) {
                cout << "Target currency not found!" << endl;
                return 0;
            }
            double baseAmount = convertToBase();
            return baseAmount / rates.at(targetCode);
        }

        virtual void displayCurrency() {
            cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
        }
};

class Dollar : public Currency {
    public:
        Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

        void displayCurrency() override {
            cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
        }
};

class Euro : public Currency {
    public:
        Euro(double amt) : Currency(amt, "EUR", "€", 0.85) {}

        void displayCurrency() override {
            cout << amount << currencySymbol << " (" << currencyCode << ")" << endl;
        }
};

class Rupee : public Currency {
    public:
        Rupee(double amt) : Currency(amt, "INR", "₹", 74.5) {}

        void displayCurrency() override {
            cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
        }
};

int main() {
    map<string, double> exchangeRates = {{"USD", 1.0}, {"EUR", 0.85}, {"INR", 74.5}};

    Currency* currencies[3];
    currencies[0] = new Dollar(100);
    currencies[1] = new Euro(100);
    currencies[2] = new Rupee(100);

    for (int i = 0; i < 3; i++) {
        currencies[i]->displayCurrency();
        cout << "Converted to USD: " << currencies[i]->convertToBase() << endl;
        cout << "Converted to EUR: " << currencies[i]->convertTo("EUR", exchangeRates) << endl << endl;
        delete currencies[i];
    }

    return 0;
}