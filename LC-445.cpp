/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int n1 = length(l1), n2 = length(l2);
        int carry = 0;
        ListNode *h = new ListNode(1);
        h->next = n1 > n2 ? add_aux(l1, l2, n1 - n2, carry) : add_aux(l2, l1, n2 - n1, carry);
        return carry == 1 ? h : h->next;
    }

private:
    int length(ListNode *l)
    {
        int len = 0;
        while (l != nullptr)
        {
            len++;
            l = l->next;
        }
        return len;
    }
    ListNode *add_aux(ListNode *l1, ListNode *l2, int k, int &carry)
    {
        if (l2 == nullptr)
            return nullptr;
        ListNode *p = new ListNode(l1->val);
        if (k > 0)
        {
            p->next = add_aux(l1->next, l2, k - 1, carry);
        }
        else
        {
            p->val += l2->val;
            p->next = add_aux(l1->next, l2->next, k, carry);
        }
        p->val += carry;
        carry = p->val / 10;
        p->val %= 10;
        return p;
    }
};