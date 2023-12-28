#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    node *next;
}node;

node *CreateList();
node *ReverseList(node *head);
void PrintList(node *head);

int main()
{
    node *list = CreateList();
    node *reversed = ReverseList(list);
    PrintList(reversed);

    return 0;
}

node *CreateList()
{
    node *head = NULL, *tail=NULL, *p = NULL;
    int num;
    cin >> num;
    while(num != -1)
    {
        p = new node;
        p->data = num;
        p->next = NULL;
        if(!head) 
            head = p;
        else
            tail->next = p;
        tail = p;

        cin >> num;
    }

    return head;
}

node *ReverseList(node *head)
{
    node *rev = NULL;
    node *p = NULL;
    while(head)
    {
        p = new node;
        p->data = head->data;
        p->next = rev;
        rev = p;

        p = head;
        head = head->next;
        delete p;
    }
    return rev;
}

void PrintList(node *head)
{
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}