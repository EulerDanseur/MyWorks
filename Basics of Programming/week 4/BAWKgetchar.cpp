#include<iostream>
using namespace std;

int main()
{
	int length, count = 0, d = 0;
	cin >> length;

    char null = getchar();

    for(int i = 0; i < length; i++)
    {
        char key;
        key = getchar();
        int c = key;
        if(c != d)
            count++;
        d = c;
    
    }
    cout << count;
    return 0;
}
