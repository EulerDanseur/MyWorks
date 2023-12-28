#include <iostream>
using namespace std;

typedef struct
{
    unsigned numi;
    unsigned deno;
} division;

int LeastCommonMultiple(unsigned a, unsigned n);

int main()
{
    int n;
    cin >> n;

    division frac[n];


    for(int i = 0; i < n; i++)
        cin >> frac[i].numi;
    for(int i = 0; i < n; i++)
    {
        cin >> frac[i].deno;
        //deno *= frac[i].deno;
    }
    
    unsigned deno = frac[0].deno;

    for(int i = 1; i < n; i++)
    {
        deno = LeastCommonMultiple(frac[i].deno, deno);
    }

    unsigned numi = 0;

    for(int i = 0; i < n; i++)
    {
        numi += frac[i].numi * (deno / frac[i].deno);
    }

    for(unsigned i = 2; i <= numi; i++)
    {
        if(deno % i == 0 && numi % i == 0)
        {
            deno /= i; numi /= i;
        }
    }
    
    if(numi == 0) deno = 1;

    cout << numi << ' ' << deno;

    return 0;
}

int LeastCommonMultiple(unsigned m, unsigned n)
{

    unsigned temp, a = n, b = m;    

    if (m < n)  
    {        
        temp = m;        
        m = n;       
        n = temp;    
    }    
 
    while((m % n)!=0)   
    {        
        temp = m % n;        
        m = n;        
        n = temp;    
    }   

    return b / n * a;
}