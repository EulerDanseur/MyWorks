#include "SmartPointer.h"
int main()
{
    SmartPointer sp1(new Node(123));
    sp1.~SmartPointer();
    sp1.assign(SmartPointer());                     // ���Կ�ָ�븳ֵ
    sp1.assign(*(new SmartPointer(new Node(456)))); // Node 456��Ȼ���ѿռ��е�ĳ��ָ����У����Բ��ᱻ�ͷ�
    sp1.~SmartPointer();
}