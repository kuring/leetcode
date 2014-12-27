#include <stdio.h>
#include <algorithm>

class Solution {
public:
	/**
	 * ����Ĺؼ����ҵ�״̬��ʽ���ҵ�״̬���̺������ӭ�ж���
	 * ״̬�������£�
	 * b[j]��ʾ��j������a[j]��β�������е�����
	 * b[j]=max(a[j] + b[j-1], a[j])
	 * b���ݵ����ֵ��Ϊ����Ľ�
	 * ����ת��Ϊ���b����
	 * ʱ�临�Ӷ�ΪO(1)���ռ临�Ӷ�Ϊ(n)���ռ临�Ӷȿ��Խ�ΪO(1)��Ϊ��ʹ�����׶�����������
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