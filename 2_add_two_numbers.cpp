/**
*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

*You may assume the two numbers do not contain any leading zero, except the number 0 itself.

*Example:

*Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
*Output: 7 -> 0 -> 8
*Explanation: 342 + 465 = 807.
**/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution using Third Linked list
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *ans = &dummy;

        int sum, carry = 0;
        ListNode *prevl1 = nullptr;
        ListNode *prevl2 = nullptr;

        while (l1 && l2)
        {
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            ans->next = new ListNode(sum % 10);
            prevl1 = l1;
            prevl2 = l2;
            l1 = l1->next;
            l2 = l2->next;
            ans = ans->next;
        }

        while (l1)
        {
            sum = l1->val + carry;
            ans->next = new ListNode(sum % 10);
            carry = sum / 10;
            l1 = l1->next;
            ans = ans->next;
        }

        while (l2)
        {
            sum = l2->val + carry;
            ans->next = new ListNode(sum % 10);
            carry = sum / 10;
            l2 = l2->next;
            ans = ans->next;
        }

        if (carry >= 1)
            ans->next = new ListNode(carry);

        return dummy.next;
    }
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode();

        ListNode *dummy = ans;

        int carry = 0;

        while (l1 || l2 || carry)
        {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            ans->next = new ListNode(sum % 10);
            ans = ans->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        // if(carry > 0)
        //     ans->next = new ListNode(carry);

        return dummy->next;
    }
};
