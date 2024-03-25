#include <iostream>
using namespace std;

class Sample
{
    static int s;

public:
    Sample(int a) { s += a; }
    static void print() { cout << "s=" << s; }
};

class MyClass
{

public:
    MyClass(int a) { x = a; } // 1
    void f(int a, int b)           // 2
    {
        x = a;
        y = b;
    }
    void f(int a, int b, int c = 0) // 3
    {
        x = a;
        y = b;
        z = c;
    }
    static void g() { x = 10; } // 4
private:
    int x, y, z;

};

int Sample::s = 0;
int main()
{
    Sample s1(1);
    Sample::print();
    Sample s2(2);
    Sample::print();
    Sample s3(3);
    Sample::print();
}