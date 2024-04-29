#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> num;

    for (int i = 1; i <= 5; i++)
    {
        num.push_back(i);
    }

    for (auto i = num.begin(); i != num.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    for (auto i = num.rbegin(); i != num.rend(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    // size() --> Number of Element
    cout << num.size() << endl;

    // max_size() --> Maximum number of Element can be handled by vecot
    cout << num.max_size() << endl;

    // capacity() --> returns size of the storage space currently allocated to the vector
    cout << num.capacity() << endl;

    // resize(n) --> resize the size of vector
    num.resize(6);

    // shrink_to_fit()
    num.shrink_to_fit();

    // reserve()
    // empty()

    // erase() --> delete a particular element
    // clear() --> remove all elements
    // swap() -->
    // emplace()
    // emplace_back()
    return 0;
}