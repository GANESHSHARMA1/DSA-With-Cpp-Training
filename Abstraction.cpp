#include <iostream>
using namespace std;

class Abtstract
{
private:
    int a = 12, b = 34, sum = 0;

public:
    int add()
    {
        sum = a + b;
        return sum;
    }
};

int main()
{
    Abtstract obj;
    cout << obj.add();
}