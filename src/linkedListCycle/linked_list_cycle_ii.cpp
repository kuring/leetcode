#include <stdio.h>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 只要写出了Linked List Cycle，再写这个就简单了
// 该问题就转换为了求解一个节点是否在一个环中
class Solution {
public:
    ListNode * detectCycle(ListNode *head) {
        if (!head)
		{
			return NULL;
		}
		ListNode *fast = head, *slow = head;
		while (fast && fast->next && slow)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				ListNode *node = head;
				while (1)
				{
					if (is_in_cycle(node, slow))
					{
						return node;
					}
					node = node->next;
				}
			}
		}
		return NULL;
    }
	
	// 判断node节点是否在cycle_node节点所在的环中
	bool is_in_cycle(ListNode *node, ListNode *cycle_node)
	{
		if (node == cycle_node)
		{
			return true;
		}
		
		ListNode *begin = cycle_node->next;
		while (begin != cycle_node)
		{
			if (begin == node)
			{
				return true;
			}
			begin = begin->next;
		}
		return false;
	}
};

int main()
{
    ListNode *node = new ListNode(0);
	node->next = node;
    Solution solution;
    cout << solution.detectCycle(node)->val << endl;
    return 1;
}
