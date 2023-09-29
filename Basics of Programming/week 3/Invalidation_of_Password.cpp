#include<iostream>
using namespace std;

/*int main()
{
    string letters;
    int supper=0, lower=0, number=0;
    cin >> letters;
    char letter;

    while(char letter : letters)
    {    
        
        if     (letter >= 'A' && letter <= 'Z')
            supper = 1;
        else if(letter >= 'a' && letter <= 'z')
            lower = 1;
        else if(letter >= '0' && letter <= '9')
            number = 1;
        else
            {
                cout << 1;
                return 0;
            }
    }

    if(supper + lower + number == 3)
        cout << 0;
    else
        cout << 1;
   
    return 0;
}*/

int main()
{
    char letter;
    int supper=0, lower=0, number=0;
    scanf("%c", &letter);

    while(letter != '\n')
    {    
        
        if     (letter >= 'A' && letter <= 'Z')
            supper = 1;
        else if(letter >= 'a' && letter <= 'z')
            lower = 1;
        else if(letter >= '0' && letter <= '9')
            number = 1;
        else
            {
                cout << 1;
                return 0;
            }
        scanf("%c", &letter);
    }

    if(supper + lower + number == 3)
        cout << 0;
    else
        cout << 1;
   
    return 0;
}


/*int main() 
{
    std::string password;
    std::cout << "Enter password: ";
    std::cin >> password;

    bool hasLowercase = false;
    bool hasUppercase = false;
    bool hasDigit = false;

    for (char ch : password) {
        if (std::islower(ch))
            hasLowercase = true;
        else if (std::isupper(ch))
            hasUppercase = true;
        else if (std::isdigit(ch))
            hasDigit = true;
    }

    if (hasLowercase && hasUppercase && hasDigit)
        std::cout << "Password meets the requirements" << std::endl;
    else
        std::cout << "Password does not meet the requirements" << std::endl;

    return 0;
}
*/

