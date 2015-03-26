#include <stdio.h>                                                                                            
#include <inttypes.h>
#include <vector>
#include <iostream>
using namespace std;

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

void print_list(ListNode *head)
{
    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << endl;
}

/*
 * for example : 1->2->3->4->5->6
 * 拆分为两个链表：1->2->3和4->5->6两个链表
 * 将4->5->6链表逆转为：6->5->4
 * 合并两个链表：1->6->2->5->3->4
 */
class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head)
        {
            return ;
        }
        
        // 拆分为两个链表
        ListNode *node = head;
        ListNode *right = head;
        int count = 0;
        while (node)
        {
            node = node->next;
            if (count > 0 && count % 2 == 0)
            {
                right = right->next;
            }
            count++;
        }
        ListNode *tmp = right;
        right = right->next;
        tmp->next = NULL;
        print_list(head);
        print_list(right);

        // 反转右边链表
        right = reverseList(right);
        print_list(right);

        // 将两个链表进行组合
        ListNode *left = head->next;
        ListNode *tail = head;
        int turn = 1;
        while (left != NULL && right != NULL)
        {
            if (turn == 0)
            {
                tail->next = left;
                left = left->next;
                turn = 1;
            }
            else if (turn == 1)
            {
                tail->next = right;
                right = right->next;
                turn = 0;
            }
            tail = tail->next;
            tail->next = NULL;
        }

        if (left != NULL)
        {
            tail->next = left;
        }
        if (right != NULL)
        {
            tail->next = right;
        }
    }

    ListNode *reverseList(ListNode *head)
    {
        if (!head)
        {
            return NULL;
        }
        ListNode *node = head;
        head = head->next;
        node->next = NULL;
        while (head)
        {
            ListNode *tmp = head->next;
            head->next = node;
            node = head;
            head = tmp;
        }
        return node;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    ListNode *head = create_list(arr, sizeof(arr) / sizeof(int));
    Solution solution;
    solution.reorderList(head);
    print_list(head);
}
