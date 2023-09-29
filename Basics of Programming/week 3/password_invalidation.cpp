#include<iostream>
using namespace std;

int main()
{   
    bool SupperLetter=false, LowerLetter=false, Number=false;
    string password;
    cin >> password;
    for(char letter : password)
    {
        if(islower(letter))
            SupperLetter=true;
        else if (isupper(letter))
            LowerLetter=true;
        else if (isdigit(letter))
            Number=true;
    }
    if(SupperLetter && LowerLetter && Number)
        cout << 0;
    else
        cout << 1;
    
    return 0;
}