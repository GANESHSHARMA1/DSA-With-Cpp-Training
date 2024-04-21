#include <iostream>
using namespace std;

class India
{
public:
    void capital()
    {
        cout << "The capital of India is 'New Delhi'" << endl;
    }
};
class USA
{
public:
    void capital()
    {
        cout << "The capital of USA is 'Washington DC'" << endl;
    }
};

int main()
{
    India objInd;
    USA objUsa;
    objInd.capital();
    objUsa.capital();
    return 0;
}
