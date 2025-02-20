#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    double price;
    string publisher;
    int stock;

public:
    Book(string t, string a, double p, string pub, int s)
        : title(t), author(a), price(p), publisher(pub), stock(s) {}

    bool isAvailable(string t, string a) const {
        return (title == t && author == a);
    }

    void displayBookDetails() const {
       cout << "Title: " << title << endl;
       cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Stock: " << stock << endl;
    }

    void sellBook(int copies) {
        if (copies <= stock) {
            double totalCost = copies * price;
            stock -= copies;
            cout << "Total Cost: $" << totalCost << endl;
        } else {
            cout << "Required copies not in stock" << endl;
        }
    }
};

int main() {
    Book inventory[2] = {
        Book("Code Hunt", "Robert", 35.50, "Agatha Wilson", 5),
        Book("C++", "Clara", 45.59, "Mella Wesley", 10)
    };

    char choice;

    do {
        string searchTitle, searchAuthor;

        cout << "Enter book title: ";
        getline(cin, searchTitle);
        cout << "Enter author: ";
        getline(cin, searchAuthor);

        bool found = false;
        for (int i = 0; i < 2; i++) {
            if (inventory[i].isAvailable(searchTitle, searchAuthor)) {
                found = true;
                inventory[i].displayBookDetails();
                int copies;
                cout << "Enter number of copies required: ";
                cin >> copies;
                inventory[i].sellBook(copies);
                break;
            }
        }

        if (!found) {
            cout << "Book not available." << endl;
        }

        cout << "Do you want to add more books (y/n)?";
        cin >> choice;
        cin.ignore();

    } while (choice != 'n');
    


    return 0;
}
