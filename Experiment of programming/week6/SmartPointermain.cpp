#include "SmartPointer.h"
int main()
{
    SmartPointer sp1(new Node(123));
    sp1.~SmartPointer();
    sp1.assign(SmartPointer());                     // 测试空指针赋值
    sp1.assign(*(new SmartPointer(new Node(456)))); // Node 456仍然被堆空间中的某个指针持有，所以不会被释放
    sp1.~SmartPointer();
}