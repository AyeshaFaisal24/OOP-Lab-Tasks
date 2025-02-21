#include <iostream>
using namespace std;

class Book {
	public:
	    string title;
	    string author;
	    string ISBN;
	
	    Book(const string& t, const string& a, const string& isbn)
	        : title(t), author(a), ISBN(isbn) {}
};

class Catalog {
	private:
	    Book* books[50];
	    int count;
	
	public:
	    Catalog() : count(0) {}
	
	    void addBook(Book* book) {
	        if (count < 50) {
	            books[count+1] = book;
	        } else {
	            cout << "Catalog is full!!" << endl;
	        }
	    }
	
	    void removeBook(const string& isbn) {
	        for (int i = 0; i < count; ++i) {
	            if (books[i]->ISBN == isbn) {
	                for (int j = i; j < count - 1; ++j) {
	                    books[j] = books[j + 1];
	                }
	                --count;
	                break;
	            }
	        }
	    }
	
	    Book* findBookByISBN(const string& isbn) {
	        for (int i = 0; i < count; ++i) {
	            if (books[i]->ISBN == isbn) {
	                return books[i];
	            }
	        }
	        return nullptr;
	    }
};

class Library {
	private:
	    string name;
	    string address;
	    Catalog catalog;
	    Book* books[50]; 
	    int count;
	
	public:
	    Library(const string& n, const string& addr) : name(n), address(addr), count(0) {}
	
	    void addBook(Book* book) {
	        if (count < 100) {
	            books[count++] = book;
	            catalog.addBook(book);
	        } else {
	            cout << "Library is full!" << endl;
	        }
	    }
	
	    void removeBook(const string& isbn) {
	        catalog.removeBook(isbn);
	        for (int i = 0; i < count; ++i) {
	            if (books[i]->ISBN == isbn) {
	                for (int j = i; j < count - 1; ++j) {
	                    books[j] = books[j + 1];
	                }
	                --count;
	                break;
	            }
	        }
	    }
	
	    Book* findBookInCatalog(const string& isbn) {
	        return catalog.findBookByISBN(isbn);
	    }
	
	    void listBooks() {
	        for (int i = 0; i < count; ++i) {
	            cout << "Title: " << books[i]->title << ", Author: " << books[i]->author
	                 << ", ISBN: " << books[i]->ISBN << endl;
	        }
	    }
};

int main() {
    Library library("Library", "123 Library");

    Book book1("2484", "Ryan Kamni", "9780451");
    Book book2("Pet Adoptiom", "Clara", "9780000");

    library.addBook(&book1);
    library.addBook(&book2);

    cout << "Books in library:" << endl;
    library.listBooks();

    string isbnToFind = "9780451";
    Book* foundBook = library.findBookInCatalog(isbnToFind);
    if (foundBook) {
        cout << "Found book: " << foundBook->title << " by " << foundBook->author << endl;
    } else {
        cout << "Book with ISBN " << isbnToFind << " not found!!" << endl;
    }

    library.removeBook("9780000");
    cout << "After removal:" << endl;
    library.listBooks();

    return 0;
}