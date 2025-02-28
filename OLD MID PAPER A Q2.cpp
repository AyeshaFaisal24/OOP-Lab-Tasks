#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
	string title;
    string author;
    bool available;
    
	public:
	    Book(string title, string author) 
	        : title(title), author(author), available(true) {}
	
	    bool borrow() {
	        if (available) {
	            available = false;
	            return true;
	        }
	        return false;
	    }
	
	    void returnBook() {
	        available = true;
	    }
	
	    string getInfo() const {
	        return "Title: " + title + ", Author: " + author + ", Available: " + (available ? "Yes" : "No");
	    }
	
	    bool isAvailable() const {
	        return available;
	    }
	
	    string getTitle() const {
	        return title;
	    }
};

class Member {
	string name;
    int id;
    vector<Book*> borrowedBooks;
    
	public:
	    Member(string name, int id) 
	        : name(name), id(id) {}
	
	    void borrowBook(Book& book) {
	        if (book.borrow()) {
	            borrowedBooks.push_back(&book);
	        }
	    }
	
	    void returnBook(Book& book) {
	        for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
	            if (*it == &book) {
	                book.returnBook();
	                borrowedBooks.erase(it);
	                break;
	            }
	        }
	    }
	
	    string getInfo() const {
	        string info = "Name: " + name + ", ID: " + to_string(id) + ", Borrowed Books: ";
	        for (const auto& book : borrowedBooks) {
	            info += book->getInfo() + "; ";
	        }
	        return info;
	    }
	
	    int getBorrowedCount() const {
	        return borrowedBooks.size();
	    }
	
	    int getId() const {
	        return id;
	    }
};

class Library {
	vector<Book> books;
    vector<Member> members;
    
	public:
	    void addBook(const Book& book) {
	        books.push_back(book);
	    }
	
	    void addMember(const Member& member) {
	        members.push_back(member);
	    }
	
	    void borrowBook(int memberId, const string& title) {
	        for (auto& member : members) {
	            if (member.getId() == memberId) {
	                for (auto& book : books) {
	                    if (book.getTitle() == title && book.isAvailable()) {
	                        member.borrowBook(book);
	                        break;
	                    }
	                }
	                break;
	            }
	        }
	    }
	
	    int getTotalBorrowedBooks() const {
	        int total = 0;
	        for (const auto& member : members) {
	            total += member.getBorrowedCount();
	        }
	        return total;
	    }
	
	    void displayMembers() const {
	        for (const auto& member : members) {
	            cout << member.getInfo() << endl;
	        }
	    }
};

int main() {
    Library library;

    library.addBook(Book("Introduction to Programming", "John Smith"));
    library.addBook(Book("Data Structures and Algorithms", "Jane Doe"));

    library.addMember(Member("John", 1));
    library.addMember(Member("Sarah", 2));
    library.addMember(Member("Michael", 3));

    library.borrowBook(1, "Introduction to Programming");
    library.borrowBook(2, "Data Structures and Algorithms");
    library.borrowBook(3, "Introduction to Programming");

    library.displayMembers();

    cout << "Total borrowed books: " << centralLibrary.getTotalBorrowedBooks() << endl;

    return 0;
}
