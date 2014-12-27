#include <stdio.h>
#include <algorithm>

class Solution {
public:
	/**
	 * 问题的关键是找到状态方式，找到状态方程后问题就迎刃而解
	 * 状态方程如下：
	 * b[j]表示第j处，以a[j]结尾的子序列的最大和
	 * b[j]=max(a[j] + b[j-1], a[j])
	 * b数据的最大值即为问题的解
	 * 问题转换为求解b数组
	 * 时间复杂度为O(1)，空间复杂度为(n)，空间复杂度可以降为O(1)，为了使程序易读，不做调整
	 */
	int maxSubArray(int A[], int n) {
		if (n == 0)
		{
			return 0;
		}
		int *b = new int[n];
		b[0] = A[0];
		int max_b = b[0];
		for (int i=1; i<n; i++)
		{
			b[i] = std::max(A[i] + b[i-1], A[i]);
			if (max_b < b[i])
			{
				max_b = b[i];
			}
		}
		delete[] b;
		return max_b;
	}
};

int main()
{
	int A[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	Solution solution;
	printf("solution=%d\n", solution.maxSubArray(A, 9));
	return 1;
}