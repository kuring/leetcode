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

ListNode* insertionSortList(ListNode* head) 
{
    if (head == NULL)
    {
        return NULL;
    }
    
    // 初始化
    ListNode *node = head->next;
    ListNode *new_head = head;
    new_head->next = NULL;
    while (node != NULL)
    {
        ListNode *node_next = node->next;   // 先将当前遍历的下一个节点保存
        
        // 将当前节点插入到新链表中
        ListNode *new_node_tmp = new_head;
        if (node->val < new_node_tmp->val)
        {
            // 当前节点插入新链表的第一个位置
            node->next = new_head;
            new_head = node;
        }
        else
        {
            // 将当前节点插入到中间
            while (new_node_tmp->next != NULL)
            {
                if (node->val < new_node_tmp->next->val)
                {
                    node->next = new_node_tmp->next;
                    new_node_tmp->next = node;
                    break;
                }
                new_node_tmp = new_node_tmp->next;
            }
            
            // 将该节点插入到最后位置
            if (new_node_tmp->next == NULL)
            {
                new_node_tmp->next = node;
                node->next = NULL;
            }
        }
            
        // 开始遍历当前节点的下一个节点
        node = node_next;
    }
    return new_head;
}

int main()
{
    // init list
    int arr[] = {4, 5, 2, 6, 7, 9};
    ListNode *head = create_list(arr, sizeof(arr) / sizeof(int));
    head = insertionSortList(head);
    print_list(head);
    return 1;
}
