#include <iostream>
using namespace std;

class AA
{
public:
    virtual void f() { cout << "¡°AA¡±"; }
};
class BB : public AA
{
public:
    BB() { cout << "BB"; }
};
class CC : public BB
{
public:
    virtual void f()
    {
        BB::f();
        cout << "¡°CC¡±";
    }
};
class XX
{
protected:
    int k;

public:
    XX(int n = 5) : k(n) {}
    ~XX() { cout << "XX"; }
    virtual void f() 
    { 
        cout << k + 3; 
    }
};
class YY : public XX
{
public:
    ~YY() { cout << "YY"; }
    void f()
    {
        cout << k - 3;
        XX::f();
    }
};
int main()
{
    /*     AA aa, *p;
        BB bb;
        CC cc;
        p = &cc;
        p->f(); */
    XX &p = *new YY;
    p.f();
    delete &p;
}