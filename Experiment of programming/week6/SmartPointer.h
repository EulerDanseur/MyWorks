#include <iostream>
class Node;
class SmartPointer
{
  Node *pointer;
  int *ref_cnt;

public:
  SmartPointer()
  {
    // ��ָ��
    pointer = nullptr;
    ref_cnt = nullptr;
  }
  SmartPointer(Node *p)
  {
    pointer = p;
    ref_cnt = new int(1);
  }

  // ��Ҫ��ɵĺ���
  SmartPointer(const SmartPointer &sptr);
  void assign(const SmartPointer &sptr); // ָ�븳ֵ����sptr��ֵ����ָ��
  ~SmartPointer();                       // ����������ע�⣺Ϊͨ��������������Ҫ��֤�����������Ա��ظ�����
};

class Node
{
public:
  int id;
  Node(int id)
  {
    this->id = id;
  }
  ~Node()
  {
    std::cout << id << ' ';
  }
};
