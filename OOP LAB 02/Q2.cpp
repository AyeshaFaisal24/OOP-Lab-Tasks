#include <iostream>
using namespace std;

void* add(void* array, void* count, void* addValue) {
    int* intArray = static_cast<int*>(array);
    int intCount = *static_cast<int*>(count); 
    int value = *static_cast<int*>(addValue);  

    for (int i = 0; i < intCount; i++) {
        intArray[i] += value;
    }
    return static_cast<void*>(intArray);
}

int main(int argc, char* argv[]) {
    int n, addValue;
    
    if (argc < 3) {
        cout << "Enter the array size: ";
        cin >> n;
        cout << "Enter the value to add: ";
        cin >> addValue;

        int* array = new int[n];

        cout << "Please enter " << n << " elements for the array: ";
        for (int i = 0; i < n; i++) {
            cin >> array[i];
        }

        cout << "Original Array:" << endl;
        for (int i = 0; i < n; i++) {
            cout << array[i] << " ";
        }
        cout << endl;

        void* modifiedArray = add(array, &n, &addValue);

        cout << "Modified Array (after adding " << addValue << " to each element):" << endl;
        int* intArray = static_cast<int*>(modifiedArray);
        for (int i = 0; i < n; i++) {
            cout << intArray[i] << " ";
        }
        cout << endl;

        delete[] array;
    } else {
        n = atoi(argv[1]);
        addValue = atoi(argv[2]);

        int* array = new int[n];

        for (int i = 0; i < n; i++) {
            if (i + 3 < argc) {
                array[i] = atoi(argv[i + 3]);
            } else {
                cout << "Please provide all " << n << " array elements!" << endl;
                delete[] array;
                return 1;
            }
        }

        cout << "Original Array:" << endl;
        for (int i = 0; i < n; i++) {
            cout << array[i] << " ";
        }
        cout << endl;

        void* modifiedArray = add(array, &n, &addValue);

        cout << "Modified Array (after adding " << addValue << " to each element):" << endl;
        int* intArray = static_cast<int*>(modifiedArray);
        for (int i = 0; i < n; i++) {
            cout << intArray[i] << " ";
        }
        cout << endl;

        delete[] array;
    }

    return 0;
}
