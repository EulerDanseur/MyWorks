#include <iostream>
using namespace std;

int calculate(string expr);
int main()
{
    string expr;
    getline(cin, expr);
    cout << calculate(expr);        

    return 0;

}

int calculate(string expr)
{
   int num1, num2;
   for(int i = 0; i < expr.length(); i++)
   {
        if(expr[i] >= 0 && expr[i] <= 9)
            continue;    
   }
}