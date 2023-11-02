#include<iostream> 
using namespace std;
void PrimeFactorization(int n); 

int main() 
{ 
    int n; 
    cin >> n; 
    PrimeFactorization(n); 
    return 0; 
}

void PrimeFactorization(int n)
{ 
    int factor = 2; 
    while (n % factor != 0) 
         factor++; 
    int count = 0; 
    while (n % factor == 0) 
    { 
        count++; 
        n /= factor; 
    } 
    cout << factor << "(" << count << ")"; 
    if (n > 1) 
        PrimeFactorization(n); 
} 