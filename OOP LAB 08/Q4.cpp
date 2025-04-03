#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
    protected:
        string name;
        string id;
        string address;
        string phoneNumber;
        string email;

    public:
        Person(string n, string i, string addr, string phone, string e)
            : name(n), id(i), address(addr), phoneNumber(phone), email(e) {}

        virtual void displayInfo() {
            cout << "Name: " << name << endl;
            cout << "ID: " << id << endl;
            cout << "Address: " << address << endl;
            cout << "Phone: " << phoneNumber << endl;
            cout << "Email: " << email << endl;
        }

        void updateInfo(string addr, string phone, string e) {
            address = addr;
            phoneNumber = phone;
            email = e;
        }
};

class Student : public Person {
    string courseEnrolled;
    double GPA;
    int enrollmentYear;

    public:
        Student(string n, string i, string addr, string phone, string e, 
                string course, double gpa, int year)
            : Person(n, i, addr, phone, e), courseEnrolled(course), GPA(gpa), enrollmentYear(year) {}

        void displayInfo() override {
            Person::displayInfo();
            cout << "Course: " << courseEnrolled << endl;
            cout << "GPA: " << GPA << endl;
            cout << "Enrollment Year: " << enrollmentYear << endl;
        }
};

class Professor : public Person {
    string department;
    vector<string> coursesTaught;
    double salary;

    public:
        Professor(string n, string i, string addr, string phone, string e,
                string dept, double sal)
            : Person(n, i, addr, phone, e), department(dept), salary(sal) {}

        void addCourse(string course) {
            coursesTaught.push_back(course);
        }

        void displayInfo() override {
            Person::displayInfo();
            cout << "Department: " << department << endl;
            cout << "Salary: $" << salary << endl;
            cout << "Courses Taught: ";
            for (const auto& course : coursesTaught) {
                cout << course << ", ";
            }
            cout << endl;
        }
};

class Staff : public Person {
    string department;
    string position;
    double salary;

    public:
        Staff(string n, string i, string addr, string phone, string e,
            string dept, string pos, double sal)
            : Person(n, i, addr, phone, e), department(dept), position(pos), salary(sal) {}

        void displayInfo() override {
            Person::displayInfo();
            cout << "Department: " << department << endl;
            cout << "Position: " << position << endl;
            cout << "Salary: $" << salary << endl;
        }
};

class Course {
    string courseId;
    string courseName;
    int credits;
    string instructor;
    string schedule;

    public:
        Course(string id, string name, int cred, string instr, string sched)
            : courseId(id), courseName(name), credits(cred), instructor(instr), schedule(sched) {}

        void displayInfo() {
            cout << "Course ID: " << courseId << endl;
            cout << "Name: " << courseName << endl;
            cout << "Credits: " << credits << endl;
            cout << "Instructor: " << instructor << endl;
            cout << "Schedule: " << schedule << endl;
        }
};

int main() {
    Person* people[3];
    people[0] = new Student("Alina", "S001", "123 Campus Rd", "555-1234", "alina@gmail.edu", 
                           "Computer Science", 3.8, 2020);
    people[1] = new Professor("Bob Don", "P001", "456 Faculty Ave", "555-5678", "don@gmail.edu",
                             "Computer Science", 80000);
    dynamic_cast<Professor*>(people[1])->addCourse("CS101");
    dynamic_cast<Professor*>(people[1])->addCourse("CS201");
    people[2] = new Staff("Carl Khan", "ST001", "789 Admin Blvd", "555-9012", "carl@gmail.edu",
                         "Administration", "Manager", 60000);

    for (int i = 0; i < 3; i++) {
        people[i]->displayInfo();
        cout << endl;
        delete people[i];
    }

    Course cs101("CS101", "Introduction to Programming", 4, "Bob", "Mon/Wed 10-11:30");
    cs101.displayInfo();

    return 0;
}