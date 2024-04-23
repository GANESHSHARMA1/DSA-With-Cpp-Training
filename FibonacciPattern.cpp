#include <iostream>
using namespace std;

int drawFibonacciPattern(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return drawFibonacciPattern(n - 1) + drawFibonacciPattern(n - 2);
}

int main()
{
    int n = 5;
    int a = 0, b = 1, c = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            c = a + b;
            cout << a << " ";
            a = b;
            b = c;
        }
        cout << endl;
    }

    return 0;
}