#include <iostream>
#include <forward_list>
#include <unordered_set>
using namespace std;

void removeDuplicates(list<int> &List)
{
    unordered_set<int> s;
    forw
        list<int>::iterator it = List.begin();
    while (it != List.end())
    {
        if (s.find(*it) == s.end())
            s.insert(*it);
        else
            remove(*it);
    }
    if (List.empty())
    {
        cout << " List is Empty";
    }
    if (s.empty())
    {
        cout << "Set is Empty";
    }
    for (int &val : s)
    {
        cout << val << " ";
    }
}

int main()
{
    forward_list<int> List;
    forward_list<int>::iterator it;
    List.push_back(2);
    List.push_back(1);
    List.push_back(5);
    List.push_back(2);
    List.push_back(6);
    List.push_back(7);
    List.push_back(3);
    List.push_back(2);
    for (it = List.begin(); it != List.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    removeDuplicates(List);
    for (it = List.begin(); it != List.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}