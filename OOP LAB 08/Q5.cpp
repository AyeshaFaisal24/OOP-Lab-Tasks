#include <iostream>
#include <string>
using namespace std;

class Media {
    protected:
        string title;
        string publicationDate;
        string uniqueID;
        string publisher;
        bool checkedOut;

    public:
        Media(string t, string date, string id, string pub)
            : title(t), publicationDate(date), uniqueID(id), publisher(pub), checkedOut(false) {}

        virtual void displayInfo() {
            cout << "Title: " << title << endl;
            cout << "Publication Date: " << publicationDate << endl;
            cout << "ID: " << uniqueID << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Status: " << (checkedOut ? "Checked Out" : "Available") << endl;
        }

        void checkOut() {
            if (checkedOut) {
                cout << "Item is already checked out!" << endl;
            } else {
                checkedOut = true;
                cout << "Item checked out successfully." << endl;
            }
        }

        void returnItem() {
            if (!checkedOut) {
                cout << "Item was not checked out!" << endl;
            } else {
                checkedOut = false;
                cout << "Item returned successfully." << endl;
            }
        }
};

class Book : public Media {
    string author;
    string ISBN;
    int numberOfPages;

    public:
        Book(string t, string date, string id, string pub, string auth, string isbn, int pages)
            : Media(t, date, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}

        void displayInfo() override {
            Media::displayInfo();
            cout << "Author: " << author << endl;
            cout << "ISBN: " << ISBN << endl;
            cout << "Pages: " << numberOfPages << endl;
        }
};

class DVD : public Media {
    string director;
    int duration;
    string rating;

    public:
        DVD(string t, string date, string id, string pub, string dir, int dur, string rate)
            : Media(t, date, id, pub), director(dir), duration(dur), rating(rate) {}

        void displayInfo() override {
            Media::displayInfo();
            cout << "Director: " << director << endl;
            cout << "Duration: " << duration << " minutes" << endl;
            cout << "Rating: " << rating << endl;
        }
};

class Magazine : public Media {
    string issueNumber;
    string editor;

    public:
        Magazine(string t, string date, string id, string pub, string issue, string edit)
            : Media(t, date, id, pub), issueNumber(issue), editor(edit) {}

        void displayInfo() override {
            Media::displayInfo();
            cout << "Issue Number: " << issueNumber << endl;
            cout << "Editor: " << editor << endl;
        }
};

int main() {
    Media* library[3];
    library[0] = new Book("The C++ Programming Language", "2013-05-19", "BK001", 
                         "Addison-Wesley", "Bjarne Stroustrup", "9780321563842", 1368);
    library[1] = new DVD("Inception", "2010-07-16", "DVD001", "Warner Bros", 
                        "Christopher Nolan", 148, "PG-13");
    library[2] = new Magazine("National Geographic", "2023-03-01", "MG001", 
                             "National Geographic Society", "March 2023", "Susan Goldberg");

    for (int i = 0; i < 3; i++) {
        library[i]->displayInfo();
        library[i]->checkOut();
        cout << endl;
        delete library[i];
    }

    return 0;
}