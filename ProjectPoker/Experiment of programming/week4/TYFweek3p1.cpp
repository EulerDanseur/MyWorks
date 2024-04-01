
#include<iostream>
#include<string>
using namespace std;
int f() {
	string str;
	cin >> str;
	int i;
	int a[3][2];
	for ( i = 0; str[i] != '\0'; i++) {
		if (str[i] == '(') {
			a[0][0]++;
			bool is = 0;
			for (int j = i; str[j] != '\0'; j++) {
				if (str[j] == ')') {
					is = 1;
					break;
				}
			}
			if (is == 0)
				return 0;
		}
		if (str[i] == ')')a[0][1]++;
		if (str[i] == '[') {
			a[1][0]++;
			bool is = 0;
			for (int j = i; str[j] != '\0'; j++) {
				if (str[j] == ']') {
					is = 1;
					break;
				}
			}
			if (is == 0)
				return 0;
		}
		if (str[i] == ']')a[1][1]++;
		if (str[i] == '{') {
			a[2][0]++;
			bool is = 0;
			for (int j = i; str[j] != '\0'; j++) {
				if (str[j] == '}') {
					is = 1;
					break;
				}
			}
			if (is == 0)
				return 0;
		}
		if (str[i] == '}')a[2][1]++;

	}
	if (a[0][0] != a[0][1] || a[1][0] != a[1][1] || a[2][0] != a[2][1])
		return 0;
	return 1;
}
int main() {
	if (f() == 1)
		cout << "true";
	else
		cout << "false";
}

