#include <iostream>
#include <cstring>
using namespace std;
char tran(char);
char list[2][27] = { 0 };

int main()
{
	int n;
	cin >> n;
	
	cin >> list[0] >> list[1];
	char sentence[301] = { 0 };
	getchar();
	for (int i = 0; i < n; i++)
	{
		cin.getline(sentence, 301);
		char* temp = sentence;
		while (*temp)
		{
			*temp = tran(*temp);
			temp++;
		}
		cout << sentence << endl;
	}

}

char tran(char c)
{
	for (int i = 0; i < 26; i++)
		if (list[1][i] == c)
			return list[0][i];
    
    return c;
}