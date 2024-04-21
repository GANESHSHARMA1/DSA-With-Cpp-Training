#include <iostream>
using namespace std;

class Hello
{
public: // Label - access Specifiers
    void static printHello()
    {
        cout << "Hello" << endl;
    }

private:
    void printHi()
    {
        cout << "Hii" << endl;
    }
};

int main()
{
    // Creating Object of Class Hello
    Hello obj;
    obj.printHello();
    // Calling Method of class Hello
    // Without declaring the Object
    Hello::printHello();
    return 0;
}