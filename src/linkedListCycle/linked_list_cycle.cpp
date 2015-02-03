#include <stdio.h>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 该解法只要掌握住了技巧，就能很快写出代码，至少该思路我想了半天没有想出来
// 设置两个指针，一个一次移动两步，一个一次移动一步
// 如果两个指针相等说明存在循环的情况，但两个指针重合的位置不确定
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head)
		{
			return false;
		}
		ListNode *fast = head, *slow = head;
		while (fast && fast->next && slow)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				return true;
			}
		}
		return false;
    }
};

int main()
{
    ListNode *node = new ListNode(0);
    Solution solution;
    cout << (solution.hasCycle(node) ? "true" : "false") << endl;
    return 1;
}
