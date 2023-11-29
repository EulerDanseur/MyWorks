#include <iostream>
using namespace std;

int main()
{
    string word;
    getline(cin, word);
    for(int i = 0; i < word.length(); i++)
    {
        if(word[i] != word[word.length() - i - 1])
        {
            cout << 'N';
            return 0;
        }
    }
    cout << 'Y';
    return 0;
}