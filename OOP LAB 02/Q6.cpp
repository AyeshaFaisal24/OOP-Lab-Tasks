#include <iostream>
#include <vector>
#include <string>

struct Subject {
    std::string subjectName;
};

struct Student {
    int id;
    Subject subjects[5]; 
};

int main() {
    std::vector<Student> students; 

    int numStudents;
    std::cout << "Enter number of students: ";
    std::cin >> numStudents;

    students.resize(numStudents);

    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Enter ID for student " << (i + 1) << ":";
        std::cin >> students[i].id;
        std::cin.ignore(); 

        for (int j = 0; j < 3; ++j) {
            std::cout << "Enter subject " << (j + 1) << " for student " << students[i].id << ":";
            std::getline(std::cin, students[i].subjects[j].subjectName);
        }
    }

    std::cout << "\nStudent Information:\n";
    for (const auto& student : students) {
        std::cout << "ID: " << student.id << "\nSubjects: ";
        for (const auto& subject : student.subjects) {
            std::cout << subject.subjectName << ",";
        }
        std::cout << endl;
    }
    
    return 0;
}
