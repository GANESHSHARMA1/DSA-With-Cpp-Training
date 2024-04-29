#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> names;
    names["BNMIT"] = 1;
    names["College"] = 2;

    for (auto i : names)
    {
        cout << i.first << " " << i.second << endl;
    }

    // at() --> returns the reference of key K
    //  begin()
    //  end()
    //  bucket() --> return the bucket w.r.t. the element key is present
    //  bucket_size() --> returns the Elements in each Bucket
    //  bucket_count() -->return number of buckets
    // empty()--> check if mapp is empty or not
    // erase() --> find an element
    return 0;
}