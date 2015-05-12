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

/**
 * 非递归实现思路
 */
ListNode* reverseList(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}
	ListNode *node = head->next;
	ListNode *new_head = head;
	new_head->next = nullptr;
	while (node != nullptr)
	{
		ListNode *tmp = node->next;
		node->next = new_head;
		new_head = node;
		node = tmp;
	}
	return new_head;
}

/**
 * 递归实现思路
 */
ListNode* reverseListRecursively(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}
	
	ListNode *left = head;
	ListNode *right = reverseListRecursively(head->next);
	head->next->next = left;
	left->next = nullptr;
	return right;
}

int main()
{
    // init list
	int arr[] = {4, 5, 2, 6, 7, 9};
    ListNode *head = create_list(arr, sizeof(arr) / sizeof(int));
	head = reverseListRecursively(head);
    print_list(head);
    return 1;
}