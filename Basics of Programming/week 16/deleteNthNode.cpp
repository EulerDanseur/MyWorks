#include <iostream>
using namespace std;

typedef struct ListNode{
     int val;
     struct ListNode *next;
}node;

node *GetList()
{
    node *head = NULL, *tail = NULL, *p = NULL;
    int i = 0;
    cin >> i;
    while(i != -1)
    {
        p = new node;
        p->val = i;
        if(!head)
            head = p;
        else
            tail->next = p;
        
        p -> next = NULL;
        tail = p;
        
        cin >> i;

    }

    return head;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
    if(head->next == NULL)
    {
        free(head);
        return NULL;
    }

    typedef struct ListNode node;
    node *prv = head, *cur = head->next, *check = head;
    for(int i = 0; i < n; i++)
    {
        check = check->next; 
    }
    if(check == NULL)
    {
        head = head->next;
        free(prv);
        return head;
    }
    while(check)
    {
        check = cur;
        for(int i = 0; i < n; i++)
            check = check->next;
        if(check == NULL)
        {
            prv->next = cur->next;
            free(cur);
            return head;
        }
        else
        {
            prv = cur;
            cur = cur->next;
        }
    }
}

struct ListNode* swapPairs(struct ListNode* head) 
{
    if(head == 0 || head->next == 0)
        return head;
    
    typedef struct ListNode node;
    node *cur = head->next;
    node *temp = cur->next;
    cur->next = head;
    head->next = temp;
    head = cur;
    cur->next->next = swapPairs(cur->next->next);

    return head;

}

node *InsertNode(node *head, node *plug)
{
    if(!head)
    {
        plug->next = NULL;
        return plug;
    }
    if(head->val > plug->val)
    {
        plug->next = head;
        return plug;
    }
    node *temp, *cur = head;
    for(cur = head; cur->next ; cur = cur->next)
    {
        if(cur->next->val > plug->val)
        {
            temp = cur->next;
            cur->next = plug;
            plug->next = temp;
            break;
        }

    }
    if(!cur->next)
    {
        cur->next = plug;
    }

    return head;
}

node *mergeTwoLists(node* list1, node* list2)
{
    node *temp = list2;
    while(temp)
    {
        temp = temp->next;
        list2->next = NULL;
        list1 = InsertNode(list1, list2);
        list2 = temp;
    }

    return list1;
}

void reorderList(node * head) 
{
    if(!head || !head->next || !head->next->next)
    {
        return ;
    }

    node *tail = head;
    while(tail->next->next)
    {
        tail = tail->next;
    }    
    node *end = tail->next;
    tail->next = NULL;
    node *temp = head->next;
    head->next = end;
    end->next = temp;
    reorderList(head->next->next); 
}


node *Reverse(node *head, int n)
{
    if(n == 1) return head;

    node *prv = head, *cur, *temp, *tail=head;
    for(int i = 0; i < n; i++)
    {
        if(!tail) return head;
        tail = tail->next;
    }
    cur = head->next;

    for(int i = 0; i < n - 1; i++)
    {
        temp = cur->next;
        cur->next = prv;
        prv = cur;
        cur = temp;
    }
    head->next = Reverse(tail, n);
    head = prv;
    return head;
} 

int main()
{
    node *head = GetList();
    //node *list = GetList();
    //int n;
    //cin >> n;
    //head = mergeTwoLists(head, list);
    reorderList(head);
    while(head)
    {
        cout << head->val << ' ';
        head = head->next;
    }
}