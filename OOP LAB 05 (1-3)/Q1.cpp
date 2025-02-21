#include <iostream>
using namespace std;

class Engine {
    public:
        bool isRunning;

        void start(){
            cout << "Engine Started!!\n";
        }
        void stop(){
            cout << "Engine Stop!!";
        }
};

class Car{
    Engine engine;
    public:
        void startCar(){
            engine.start();
        }
        void stopCar(){
            engine.stop();
        }
};

int main() {
    Car C;
    C.startCar();
    C.stopCar();

    return 0;
}

