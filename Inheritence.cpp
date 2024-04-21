#include <iostream>
using namespace std;

class A
{
public:
    void f1();
};

class B : public A // Single Level Inheritence
{
public:
    void f2();
};

class C : public A, public B // Muliple Inheritance
{
public:
    void f3();
};

// Hierachical Inheritance
class AA // parent
{
};
class BB : public AA // Child 1
{
};
class CC : public BB // Child 2
{
};

int main()
{
    C obj;
    obj.C::f3();
}