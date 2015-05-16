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

/**
 * 链表的操作复杂就复杂在对于边界的处理和指针的指向
 * 需要的逻辑性比较强
 */
ListNode* partition(ListNode* head, int x)
{
	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}
	
	ListNode *new_head = nullptr;
	ListNode *insert_site = nullptr;
	bool is_exist = false;
	if (head->val < x)
	{
		insert_site = head;
		new_head = head;
	}
	else
	{
		is_exist = true;
	}
	ListNode *node = head->next;
	ListNode *prev = head;
	while (node != nullptr)
	{
		//cout << "node=" << node->val << "   insert_site=" << (insert_site != nullptr ? insert_site->val : -1) << endl;
		if (node->val < x)
		{
			if (is_exist)
			{
				ListNode *tmp = node;
				prev->next = node->next;
				node = node->next;
				if (insert_site == nullptr)
				{
					insert_site = tmp;
					insert_site->next = head;
					new_head = insert_site;
				}
				else
				{
					tmp->next = insert_site->next;
					insert_site->next = tmp;
					insert_site = insert_site->next;
				}
			}
			else
			{
				node = node->next;
				prev = prev->next;
				insert_site = insert_site->next;
			}
		}
		else
		{
			// 不需要移动当前节点
			node = node->next;
			prev = prev->next;
			is_exist = true;
		}
		
		//print_list(new_head);
	}
	
	if (insert_site == nullptr)
	{
		new_head = head;
	}
	
	return new_head;
}

int main()
{
    int arr[] = {2,0,4,1,3,1,4,0,3};

    // init list
    ListNode *head = create_list(arr, sizeof(arr) / sizeof(int));
	head = partition(head, 4);
    print_list(head);
	
    return 1;
}
