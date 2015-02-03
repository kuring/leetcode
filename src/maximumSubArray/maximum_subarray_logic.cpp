#include <stdio.h>
#include <algorithm>
#include <limits.h>

class Solution {
public:
	/**
	 * 逻辑分析法，通过找规律来解决问题，时间复杂度为O(n)
	 */
	int maxSubArray(int A[], int n) {
		if (n == 0)
		{
			return 0;
		}
		int current_sum = 0;
        int max_sum = INT_MIN;
		
		for (int i=0; i<n; i++)
		{
            if (current_sum <= 0)
            {
                current_sum = A[i];
            }
            else
            {
                current_sum += A[i];
            }
            if (current_sum > max_sum)
            {
                max_sum = current_sum;
            }
		}
		return max_sum;
	}
};

int main()
{
	int A[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	Solution solution;
	printf("solution=%d\n", solution.maxSubArray(A, 9));
	return 1;
}
