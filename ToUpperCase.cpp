#include <iostream>
using namespace std;

void toUpperCase(string str)
{
    string res;
    for (char ch : str)
    {
        res.push_back(ch - 32);
    }
    cout << res;
}

int main()
{
    string name = "ganesh";
    toUpperCase(name);
    return 0;
}