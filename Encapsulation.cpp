#include <iostream>
using namespace std;

class Employee
{
private:
    string name;
    int sal;

public:
    string getName() // Getter Function
    {
        return name;
    }

    void setName(string name) // Setter Function
    {
        this->name = name;
    }
};

int main()
{
    Employee e1;
    e1.setName("Ganesh");
    cout << e1.getName();
    return 0;
}