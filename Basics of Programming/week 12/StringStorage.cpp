#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a;//存储原始字符串
	string b;//逆序储存原始字符串
	getline(cin, a);
	int n = a.length();//计算原始字符串长度
	for (int i = 0; i < n; i++)
		b[i] = a[n -1- i];
	//cout << a << endl << b;
	cout << b;
    return 0;
}