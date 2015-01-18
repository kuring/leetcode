#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/**
 * 我对题目的理解有点问题，rotate the list to the right by k places我理解的是将链表开头的元素放到链表尾部，而题目的真实意思是将链表尾部的元素放到链表头部
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || k == 0)
        {
            return head;
        }

        // 求得链表的长度
        ListNode *pre = head;
        int count = 0;
        while (pre)
        {
            count++;
            pre = pre->next; 
        } 
        // 针对k大于链表长度的情况作处理
        k %= count;
        if (k == 0)
        {
            return head;
        }

        pre = head;
        count = 0;
        ListNode *post = head;
        while (post->next)
        {
            if (count >= k)
            {
                pre = pre->next;
            }
            count++;
            post = post->next;
        }

        ListNode *tmp = pre->next;
        pre->next = NULL;
        pre = tmp;
        post->next = head;
        return pre;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution solution;
    head = solution.rotateRight(head, 5);
    while (head != NULL)
    {
        printf("%d\t", head->val);
        head = head->next;
    }
    return 1;
}
