#include <stdio.h>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *create_list(int arr[], int size)
{
    if (size == 0)
    {
        return NULL;
    }
    ListNode *head = new ListNode(arr[0]);
    ListNode *node = head;
    for (int i=1; i<size; i++)
    {
        ListNode *tmp = new ListNode(arr[i]);
        node->next = tmp;
        node = node->next;
    }
    return head;
}


/**
 * 首先分别求得两个链表的长度
 * 然后让两个链表的起点位置对齐后开始逐个节点比较
 * 暂未发现比这更好的算法
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length_a = 0, length_b = 0;
        ListNode *node_a = headA, *node_b = headB;
        while (node_a)
        {
            length_a++;
            node_a = node_a->next;
        }
        while (node_b)
        {
            length_b++;
            node_b = node_b->next;
        }
        node_a = headA;
        node_b = headB;
        if (length_a > length_b)
        {
            int count = 0;
            while (count <= (length_a - length_b - 1))
            {
                count++;
                node_a = node_a->next;
            }
        }
        else
        {
            int count = 0;
            while (count <= (length_b - length_a - 1))
            {
                count++;
                node_b = node_b->next;
            }
        }

        while (node_a && node_b)
        {
            if (node_a == node_b)
            {
                return node_a;
            }
            node_a = node_a->next;
            node_b = node_b->next;
        }
        return NULL;
    }
};

void print_list(ListNode *head)
{
    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
}

int main()
{
    int arr_a[] = {1, 2, 3, 4, 5};
    int arr_b[] = {1, 2};
    ListNode *head_a = create_list(arr_a, sizeof(arr_a) / sizeof(int));
    ListNode *head_b = create_list(arr_b, sizeof(arr_b) / sizeof(int));
//    ListNode *head_a = new ListNode(3);
//    ListNode *head_b = new ListNode(2);
//    head_b->next = head_a;
    Solution solution;
    solution.getIntersectionNode(head_a, head_b);
    return 1;
}
