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
	ListNode *new_head = nullptr;		// �������ͷ��
	ListNode *node = head;
	bool is_same = false;
	
	// ѭ���ҵ���������ĵ�һ����ַ
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
	
	// �ظ���飬���õݹ鷽ʽ����1,1,2,2�����
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
 * �ҵĳ����߼��϶������ˣ����ұ��������Ҫ���ӵĶ࣬��Ȼʱ�临�ӶȲ����ߣ�����ȴ�õ���3��whileѭ��
 * �ó���һ��whileѭ�����㹻��
 * ����Ϊ���߼������Ƴ�����
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
	
	// ��������ͷ����ʼȥ��
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
