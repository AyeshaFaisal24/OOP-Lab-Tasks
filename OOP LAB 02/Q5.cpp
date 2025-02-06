#include <iostream>
#include <string>
using namespace std;

struct Person {
    int id;
    string name;
};

void swap(Person &a, Person &b) {
    Person temp = a;
    a = b;
    b = temp;
}

void sortByIdThenName(Person people[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (people[j].id > people[j + 1].id || 
               (people[j].id == people[j + 1].id && people[j].name[0] > people[j + 1].name[0])) {
                swap(people[j], people[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of records: ";
    cin >> n;

    Person people[N]; 

    for (int i = 0; i < N; i++) {
        cout << "Enter ID and Name for record " << i + 1 << ": ";
        cin >> people[i].id >> people[i].name;
    }

    sortByIdThenName(people, N);

    cout << "Sorted by ID and then first character of Name" << endl;
    for (int i = 0; i < N; i++) {
        cout << "ID: " << people[i].id << ", Name: " << people[i].name << endl;
    }

    return 0;
}
