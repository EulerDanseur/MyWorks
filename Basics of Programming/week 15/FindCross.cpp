#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    node *next;
}node;

const node *findFirstCross(const node *head1, const node *head2);
node *makeCross(node *head1, node *head2, int k);
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
void printList(node *head)
{
    while(head)
    {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
}

int main()
{
    node *head1=CreateList();
    node *head2=CreateList();
    int k;
    cin >> k;
    printList(head1), printList(head2);
    node *cur = head1;
    if(cur = makeCross(head1, head2, k))
    {    
        node *curr = cur;
        for(int i = 1; i < k; i++)
        {
            curr = curr->next;
        }
        cout << curr << endl;
        cout << findFirstCross(head1, head2)<< endl;
        
    }
    else
    {
        cout << 0 << endl;
    }
    printList(head1), printList(head2);
    return 0;
}

node *makeCross(node *head1, node *head2, int k)
{
    node *result = head1;
    node *result2 = head2;
    if(!head1 || !head2)
    {
        return NULL;
    }

    bool flag = 1;
    for(int i = 0; i < k - 2; i++)
    {
        if(!(head1 && head2 && head1->next && head2->next))
        {
            return 0;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    if(!(head1 && head2 && head1->next && head2->next))
    {
        return 0;
    }

    if(flag)
    {
        node *del = head1->next;
        node *cur = del;
        while(del)
        {
            cur = del->next;
            delete del;
            del = cur;
        }
        head1->next = head2->next;
        
        if(k == 1)
        {
            delete head1;
            return result2;
        }

        return result;
    }
}

const node *findFirstCross(const node *head1, const node *head2)
{
    while(head1 && head2)
    {
        if(head1 == head2)
        {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}