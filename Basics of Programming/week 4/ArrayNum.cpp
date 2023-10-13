#include <iostream>
#include<string>
using namespace std;

int type(string x) {
	int m = 0;
	if (x.length() == 1)
		m++;
	else if (x.length() == 2 && (x[0] == x[1] || x[0] == 48 || x[1] == 48))
		m++;
	else{
		for (int i = 2; i < x.length(); i++) {
			if ((x[i] - x[i - 1]) != (x[i - 1] - x[i - 2])) {
				m++;
				break;
			}
			if (x[i] - x[i - 1] == 0 || x[i - 1] - x[i - 2] == 0) {
				m++;
				break;
			}
			if (x[i - 2] == 48 || x[i - 1] == 48 || x[i] == 48) {
				m++;
				break;
			}
		}
	}
	if (m != 0)
		return -1;
	else
		return x[0]+x[x.length() - 1] - 96;
}

int main() {
	unsigned n;
	string X[6000];
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
    	cin >> X[i];
		cout << type(X[i])<<endl;
    }
}