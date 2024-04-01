检查要点:
1 类的结构是否正确
2 成员函数的原型是否正确
3 派生时是否定义了虚函数
4 在主函数中是否实现动态的多态性
共 3 个小题,实现在一个程序中,做为第一次作业提交。
1 类的基本概念
定义一个时间类,它能表示时、分、秒,并提供以下操作。编写程序测试类的功能。
(1)Time (int h, int m, int s);//构造函数
(2) Time (Time const &x) //拷贝构造函数
(3) void set(int h, int m, int s);//设置时间
(4)Time & increment();//自动加 1 秒
(5)void display( );//显示时间
(6)bool equal(Time const & x);//判断两个时间是否相等
(7)bool less_than(Time const &x);//比较两个时间大小
用动态链接库的方法,隐藏类的实现细节.
2 操作符重载函数
为 Time 类继续添加以下成员函数,并测试
(1) 赋值操作符重载函数
 Time & operator = (Time const &x)
(2) 类型转换函数//将时间转换为秒数
 operator int( )
(3) 可用作类型转换的构造函数 Time ( int ) //将 int 类型转换为 Time 格式,如 Time(60)为
0:1:0
(4) 时间的比较 bool operator = = (Time const & x); bool operator < (Time const & x)
(5) 增加/减少若干秒 Time operator + (int n) ; Time operator – (int n)
(6) 增加/减少 1 秒
 Time & operator ++( ) ; 

Time & operator - -( )
(7) 计算两个时刻相差的秒数。int operator- ( Time const &x);
3 派生类
利用时间类 Time,定义一个带时区的时间类 ExtTime。除了构造函数和时间调整函数外,
ExtTime 的其他功能与 Time 类似。用虚函数实现函数 void display( );调用的动态绑定。
