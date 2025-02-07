#include <iostream>
using namespace std;

class User{
    public:
        int age;
        string name;
};

int main() {
    User user;
    user.name = "Teo";
    user.age = 24;

    cout << "My name is " << user.name << " and I'm " << user.age << " years old.";

    return 0;
}
