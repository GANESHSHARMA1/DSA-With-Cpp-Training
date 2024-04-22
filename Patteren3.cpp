#include <iostream>
using namespace std;

void drawpattern(int n)
{
    for (int i = 0; i < (2 * n - 1); i++)
    {
        int min = 0;
        for (int j = 0; j < (2 * n - 1); j++)
        {
            if (j > i || j > (2 * n - 2) - i)
                min--;
            cout << " " << n - min << " ";
            if (j < i || j < (2 * n - 2) - i)
                min++;
        }
        cout << endl;
    }
}

int main()
{
    drawpattern(4);
    return 0;
}