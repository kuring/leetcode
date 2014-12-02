#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
		if (head == NULL)
		{
			return head;
		}
        ListNode *node = head;
		while (node != NULL)
		{
			if (node->next == NULL)
			{
				break;
			}
			if (node->next->val == node->val)
			{
				ListNode *tmp = node->next;
				node->next = node->next->next;
				delete tmp;
			}
			else
			{
				node = node->next;
			}
		}
		return head;
    }
};

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);

	Solution solution;
	solution.deleteDuplicates(head);
	
	while (head != NULL)
	{
		printf("%d\t", head->val);
		head = head->next;
	}
:
