#include <stdio.h>
class Solution {
public:
	// 以i为根节点的数，左子树由[1,i-1]个节点构成，右子树由[i+1,n]构成
	// 以i为根节点的数的个数为左子树个数*右子树个数，问题由此转换为一个动态规划问题
	// f[n] = sum(f[i]+f[n-i-1])
	int numTrees(int n) {
		int *f = new int[n+1];
		memset(f, 0, sizeof(int)*(n+1));
		f[0] = 1;
		f[1] = 1;
		for (int i=2; i<=n; i++)
		{
			for (int j=0; j<i; j++)
			{
				f[i] += f[j] * f[i-j-1];
			}
		}
		int res = f[n];
		delete[] f;
		return res;
	}
};

int main()
{
	Solution solution;
	printf("solution=%d\n", solution.numTrees(3));
	return 1;
}
