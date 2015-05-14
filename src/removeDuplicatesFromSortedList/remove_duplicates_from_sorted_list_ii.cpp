#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

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
    std::cout << std::endl;
}

ListNode* deleteDuplicatesHead(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}
	ListNode *new_head = nullptr;		// 新链表的头部
	ListNode *node = head;
	bool is_same = false;
	
	// 循环找到的新链表的第一个地址
	while (node->next != nullptr && node->val == node->next->val)
	{
		node = node->next;
		is_same = true;
	}
	if (is_same)
	{
		new_head = node->next;
	}
	else
	{
		new_head = node;
	}
	
	if (new_head == head || new_head == nullptr)
	{
		return new_head;
	}
	
	// 重复检查，采用递归方式处理1,1,2,2的情况
	while (1)
	{
		ListNode *tmp = deleteDuplicatesHead(new_head);
		if (tmp == new_head)
		{
			break;
		}
		new_head = tmp;
	}
	return new_head;
}

/**
 * 我的程序逻辑肯定复杂了，而且比我想象的要复杂的多，虽然时间复杂度并不高，但是却用到了3个while循环
 * 该程序一个while循环就足够了
 * 不想为了逻辑而改善程序了
 */
ListNode* deleteDuplicates(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}
	
	ListNode *new_head = deleteDuplicatesHead(head);
	if (new_head == nullptr || head->next == nullptr)
	{
		return new_head;
	}
	
	// 从新链表头部开始去重
	ListNode *node = new_head->next;
	ListNode *prev = new_head;
	while (node != nullptr && node->next != nullptr)
	{
		bool is_same = false;
		while (node->next != nullptr && node->val == node->next->val)
		{
			prev->next = node->next;
			delete node;
			node = prev->next;
			is_same = true;
		}
		
		if (node->next == nullptr)
		{
			if (is_same)
			{
				prev->next = nullptr;
				delete node;
			}
			break;
		}
		
		if (is_same)
		{
			prev->next = node->next;
			delete node;
			node = prev->next;
		}
		else
		{
			prev = prev->next;
			node = node->next;
		}
	}
	
	return new_head;
}

int main()
{
    int arr[] = {1, 1, 2, 2};

    // init list
    ListNode *head = create_list(arr, sizeof(arr) / sizeof(int));
	head = deleteDuplicates(head);
    print_list(head);
	
    return 1;
}
