#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (!l1 || !l2)
        {
            return NULL;
        }
        int flag = 0;
        ListNode *prev = NULL;
        ListNode *head = NULL;
        for (; l1 && l2; )
        {
            int value = l1->val + l2->val + flag;
            flag = value / 10;
            ListNode *node = new ListNode(value % 10);
            if (prev)
            {
                prev->next = node;
                prev = node;
            }
            else
            {
                prev = node;
                head = node;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        // 处理l1不为空情况
        while (l1)
        {
            int val = flag + l1->val;
            prev->next = new ListNode(val % 10);
            l1 = l1->next;
            flag = val / 10;
            prev = prev->next;
        }
        // 处理l2不为空情况
        while (l2)
        {
            int val = flag + l2->val;
            prev->next = new ListNode(val % 10);
            l2 = l2->next;
            flag = val / 10;
            prev = prev->next;
        }
        // 处理仍有进位情况
        if (flag)
        {
            ListNode *node = new ListNode(flag);
            prev->next = node;
        }
        return head;
    }
};

int main()
{
    ListNode *l1, *l2;
    l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    Solution solution;
    ListNode *node = solution.addTwoNumbers(l1, l2);
    while (node)
    {
        cout << node->val;
        node = node->next;
    }
    cout << endl;
    return 0;
}