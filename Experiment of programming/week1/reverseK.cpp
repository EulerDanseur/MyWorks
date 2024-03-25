#include <iostream>
using namespace std;

struct Node
{
    int content;
    Node *next;
};
Node *input();
Node *reverseK(Node *head, int k);
void output(Node *head);
void remove(Node *head);

int main()
{
    Node *head = input();
    int k;
    cin >> k;
    Node *newhead = reverseK(head, k);
    output(newhead);
    remove(head);
    remove(newhead);
    return 0;
}
Node *input()
{
    Node *head = 0, *p = 0, *tail = 0;
    int num;
    cin >> num;
    while (num != -1)
    {
        p = new Node;
        p->content = num;
        p->next = 0;
        if (head == 0)
            head = p;
        else
            tail->next = p;
        tail = p;
        getchar();
        getchar();
        cin >> num;
    }
    return head;
}

void output(Node *head)
{
    while (head->next)
    {
        cout << head->content << "->";
        head = head->next;
    }
    cout << head->content;
}
Node *reverseK(Node *head, int k)
{
    bool flag = 0;
    Node *cur = head, *pre = head, *nexthead = 0, *tail = 0, *p = 0;
    for (int i = 0; i < k - 2; i++)
    {
        if (cur == 0 || pre == 0)
        {
            flag = 1;
            break;
        }
        pre = pre->next;
        cur = pre->next;
    }
    if (cur == 0)
        flag = 1;
    pre = 0;

    if (flag == 0)
    {
        for (int i = 0; i < k; i++)
        {
            nexthead = cur->next;
            p = new Node;
            p->content = head->content;
            if (tail == 0)
                tail = p;
            p->next = pre;
            pre = p;

            head = head->next;
        }
        tail->next = reverseK(nexthead, k);
    }
    else
    {
        while (head)
        {
            p = new Node;
            p->content = head->content;
            p->next = 0;
            if (pre == 0)
                pre = p;
            else
                tail->next = p;
            tail = p;
            head = head->next;
        }
    }
    /*
    Node* p = head, * q = head->next, * s = 0;
    do
    {
        s = q -> next;
        q->next = p;
        p = q;
        q = s;
    } while (q);
    */

    return pre;
}
void remove(Node *head)
{
    Node *cur = head;
    while (head)
    {
        head = head->next;
        delete cur;
        cur = head;
    }
}