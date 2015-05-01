#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

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
    std::cout << std::endl;
}

ListNode* removeElements(ListNode* head, int val)
{
    if (head == NULL)
    {
        return NULL;
    }

    // 去除头部重复节点
    while (head != NULL && head->val == val)
    {
        head = head->next;
    }

    ListNode *node = head;
    while (node && node->next)
    {
        if (node->next->val == val)
        {
            node->next = node->next->next;
        }
        else if (node->next != NULL)
        {
            node = node->next;
        }
    }
    return head;
}

int main()
{
    // init tree
    int arr[] = {1, 2, 2, 4, 5};

    // init list
    ListNode *head = create_list(arr, sizeof(arr) / sizeof(int));
    removeElements(head, 2);
    print_list(head);

    return 1;
}
