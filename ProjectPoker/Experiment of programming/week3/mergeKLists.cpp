#include <bits\stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *merge2Lists(ListNode *a, ListNode *b)
{
    if (!(a && b))
        return (a ? a : b);
    ListNode head, *tail = &head, *ap = a, *bp = b;
    while (ap && bp)
    {
        if (ap->val < bp->val)
        {
            tail->next = ap;
            ap = ap->next;
        }
        else
        {
            tail->next = bp;
            bp = bp->next;
        }
        tail = tail->next;
    }
    tail->next = (ap ? ap : bp);

    return head.next;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *head = 0;
    for (auto p = lists.begin(); p != lists.end(); p++)
    {
        head = merge2Lists(head, *p);
    }

    return head;
}
int main()
{
}