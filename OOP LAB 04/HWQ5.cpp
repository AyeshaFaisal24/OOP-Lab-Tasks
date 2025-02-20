#include <iostream>

using namespace std;

struct MenuItem {
    string name;
    string type; 
    double price;
};

class CoffeeShop {
private:
    string name;
    MenuItem menu[10]; 
    string orders[10]; 
    int menuSize;
    int orderCount;

public:
    CoffeeShop(string shopName, MenuItem shopMenu[], int size) {
        name = shopName;
        menuSize = size;
        for (int i = 0; i < size; i++) {
            menu[i] = shopMenu[i];
        }
        orderCount = 0;
    }

    string addOrder(string itemName) {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].name == itemName) {
                orders[orderCount++] = itemName;
                return "Order added: " + itemName;
            }
        }
        return "This item is currently unavailable";
    }

    string fulfillOrder() {
        if (orderCount > 0) {
            string fulfilled = orders[0];
            for (int i = 0; i < orderCount - 1; i++) {
                orders[i] = orders[i + 1];
            }
            orderCount--;
            return "The " + fulfilled + " is ready";
        }
        return "All orders have been fulfilled";
    }

    void listOrders() {
        if (orderCount == 0) {
            cout << "No orders currently." << endl;
        } else {
            for (int i = 0; i < orderCount; i++) {
                cout << orders[i] << endl;
            }
        }
    }

    double dueAmount() {
        double total = 0.0;
        for (int i = 0; i < orderCount; i++) {
            for (int j = 0; j < menuSize; j++) {
                if (orders[i] == menu[j].name) {
                    total += menu[j].price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        double minPrice = menu[0].price;
        string cheapest = menu[0].name;
        for (int i = 1; i < menuSize; i++) {
            if (menu[i].price < minPrice) {
                minPrice = menu[i].price;
                cheapest = menu[i].name;
            }
        }
        return cheapest;
    }

    void drinksOnly() {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "drink") {
                cout << menu[i].name << endl;
            }
        }
    }

    void foodOnly() {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "food") {
                cout << menu[i].name << endl;
            }
        }
    }
};

int main() {
    MenuItem menu[] = {
        {"Coffee", "drink", 2.5},
        {"Tea", "drink", 1.5},
        {"Sandwich", "food", 5.89},
        {"Cake", "food", 3.0}
    };
    
    CoffeeShop shop("Cafe Bliss", menu, 4);
    
    cout << shop.addOrder("Coffee") << endl;
    cout << shop.addOrder("Burger") << endl;
    
    shop.listOrders();
    cout << "Total Due: $" << shop.dueAmount() << endl;
    
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    
    cout << "Cheapest Item: " << shop.cheapestItem() << endl;
    
    cout << "Drinks Only:" << endl;
    shop.drinksOnly();
    
    cout << "Food Only:" << endl;
    shop.foodOnly();
    
    return 0;
}
