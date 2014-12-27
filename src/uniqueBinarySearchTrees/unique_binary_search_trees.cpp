#include <stdio.h>
class Solution {
public:
	// ��iΪ���ڵ��������������[1,i-1]���ڵ㹹�ɣ���������[i+1,n]����
	// ��iΪ���ڵ�����ĸ���Ϊ����������*�����������������ɴ�ת��Ϊһ����̬�滮����
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
