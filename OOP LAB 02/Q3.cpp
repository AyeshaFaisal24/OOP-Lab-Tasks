#include <iostream>
using namespace std;

int main() {
    int size = 5;  
    int elements = 0;      
    int* array = new int[size];

    cout << "Start entering numbers (enter 0 to stop):" << endl;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        if (elements >= size * 2) {
            int newSize = size * 2;
            int* newArray = new int[newSize];
            for (int i = 0; i <size; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
            size = newSize;
            cout << "Array resized to capacity: " << size << endl;
        }
        array[elements++] = n;
    }

    int* finalArray = new int[elements];
    for (int i = 0; i < elements; i++) {
        finalArray[i] = array[i];
    }
    delete[] array;
    array = finalArray;
    size = elements;
    cout << "Final resized array capacity: " << size << endl;

    cout << "Final array: ";
    for (int i = 0; i < elements; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;
    return 0;
}
