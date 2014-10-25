// 我的实现方式要比陈皓的简单许多
// 仅需要一遍循环即可完成
#include <stdio.h>

class Solution {
public:
	bool isPalindrome(int x)
	{
		if (x < 0)
		{
			return false;
		}
		int temp = x;
		int y = 0;
		while (temp != 0)
		{
			y = y * 10 + temp % 10;
			temp = temp / 10;
		}
		return x == y;
	}

};

int main()
{
	Solution solution;
	printf("%d %s\n", 12321, solution.isPalindrome(12321) ? "yes" : "no");
}
