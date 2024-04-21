#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (i == 0 && j % 3 != 0)
            {
                cout << " * ";
            }
            else if (i == 1 && j % 3 == 0)
            {
                cout << " * ";
            }
            else if (i - j == 2)
            {
                cout << " * ";
            }
            else if (i + j == 8)
            {
                cout << " * ";
            }
            else
            {
                cout << "   ";
            }
        }
        cout << endl;
    }
    return 0;
}

/*
  1 2 3 4 5 6 7
1   * *   * *
2 *     *     *
3 *           *
4   *       *
5     *   *
6       *
*/