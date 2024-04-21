#include <iostream>
using namespace std;

void function()
{
    // In next call value of Auto
    // varialbe will be called
    int x = 10; // Auto Variable
    static int y = 10;
    cout << x << " " << y << endl;
    x++;
    y++;
}

void function1()
{
    a = 20;
    cout << a << endl;
}
extern int a;

int main()
{
    function(); // 10 10
    function(); // 10 11
    function1();
    return 0;
}