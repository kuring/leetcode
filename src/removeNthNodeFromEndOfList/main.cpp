// 跟haoel的基本思想一致，但是haoel中少了释放内存的操作
#include <stdio.h>

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

public:

    ListNode *removeNthFromEnd(ListNode *head, int n) {
		if (head == NULL || n <=0)
		{
			return NULL;
		}
		ListNode *pNode = head;
		ListNode *pResult = NULL;
		int count = 0;
		while (pNode != NULL)
		{
			count++;
			if (count == n + 1)
			{
				pResult = head;
			}
			else if (pResult != NULL)
			{
				pResult = pResult->next;
			}
			pNode = pNode->next;
		}
		if (pResult == NULL)
		{
			ListNode *result = head->next;
			delete head;
			return result;
		}

		ListNode *tmp = pResult->next;
		pResult->next = tmp->next;
		delete tmp;
		return head;
    }

};

int main()
{
	// init
	ListNode *head = new ListNode(1);
	ListNode *pNode = head;
	for (int i=2; i<=5; i++)
	{
		pNode->next = new ListNode(i);
		pNode->next->next = NULL;
		pNode = pNode->next;
	}

	Solution solution;
	head = solution.removeNthFromEnd(head, 3);

	// print
	pNode = head;
	while (pNode != NULL)
	{
		printf("%d\t", pNode->val);
		pNode = pNode->next;
	}
	printf("\n");
	return 1;
}
