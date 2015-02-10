#include <stdio.h>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 只要写出了Linked List Cycle，再写这个就简单了
// 该问题就转换为了求解一个节点是否在一个环中，然后通过遍历一遍链表找到第一个在环中的链表节点
// 下面的解答思路就是按照此思路进行的,但是该问题的时间复杂度较高
// 
// 思路二：
// 找到了环后即可判断出环中的节点的数目，然后从链表开始遍历，一个快指针，一个慢指针，两者相差环中节点数目个节点，当两个节点第一次重合时即为环中的第一个节点
// 该算法时间复杂度降低
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
