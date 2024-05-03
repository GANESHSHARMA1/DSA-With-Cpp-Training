#include <iostream>
using namespace std;

class Printer
{

public:
    string _name;
    int _availablePaper;

    Printer(string name, int paper)
    {
        _name = name;
        _availablePaper = paper;
    }

    void printDoc(string textDoc)
    {
        int reqPaper = textDoc.length() / 10;
        if (reqPaper > _availablePaper)
        {
            throw 404;
            throw "Please add more paper";
        }
        cout << "Printing......" << textDoc << endl;
        _availablePaper -= reqPaper;
    }
};

int main()
{
    Printer myPrinter("HP LazerJet 5000", 10);
    try
    {
        myPrinter.printDoc("Hii my name is Ganesh Sharma, and I study in BNMIT. ");
        myPrinter.printDoc("Hii my name is Ganesh Sharma, and I study in BNMIT. Hii my name is Ganesh Sharma, and I study in BNMIT. Hii my name is Ganesh Sharma, and I study in BNMIT. Hii my name is Ganesh Sharma, and I study in BNMIT. Hii my name is Ganesh Sharma, and I study in BNMIT. Hii my name is Ganesh Sharma, and I study in BNMIT. Hii my name is Ganesh Sharma, and I study in BNMIT. Hii my name is Ganesh Sharma, and I study in BNMIT. Hii my name is Ganesh Sharma, and I study in BNMIT. ");
    }
    catch (const char *textException)
    {
        cout << "Exception: " << textException << endl;
    }
    catch (int errorCode)
    {
        cout << errorCode << ": No more Paper Available" << endl;
    }
    catch (...)
    {
        cout << "Something Unexpected Happened!!" << endl;
    }
    return 0;
}
