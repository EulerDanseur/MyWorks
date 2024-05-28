#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

//外部变量
extern HANDLE hOut;

extern char keyc;
extern string keys;
extern int keynum;

//函数声明

//设置光标位置
void pos(short x,short y);

//显示主菜单
void showMainMenu();
