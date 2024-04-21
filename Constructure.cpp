#include <iostream>
using namespace std;

class Car
{
public:
    // Attributes
    string brandName;
    int speed;

    // Contructure :- It is created If Attributes are Present
    // Contructure --> (1) Creates Object, (2) Initialize Objs
    // Contructure --> (1) Deafult Constructure, (2) Parameterized Constructure
    // Contructure :- A method of same name as of Class---> Always Public
    Car(string brandName, int speed) // No Return Type
    {
        this->brandName = brandName;
        this->speed = speed;
    }

    void printDetails()
    {
        cout << "Car Brand is : " << brandName << endl;
        cout << "Car Speed is : " << speed << endl;
    }
};

class Demo
{
public:
    // Default Constructure
    Demo()
    {
        cout << "Default Constructure!!" << endl;
    }

    // Destructor :- Delete unused objects
    // Distructor :- This is not present in Java beacause Garbage Collector
    ~Demo()
    {
        cout << "I'm a Destructor!!" << endl;
    }
};

int main()
{
    Demo obj2;
    Car c1("Audi", 200);           // Calling Constructure
    Car *c2 = new Car("BMW", 300); // Dynamic Memory Allocation
    c1.printDetails();
    c2->printDetails();
    return 0;
}