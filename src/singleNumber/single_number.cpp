#include <stdio.h>
#include <algorithm>
#include <limits.h>

/**
 * 利用异或的特点
 */
class Solution {
public:
	int singleNumber(int A[], int n) {
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result ^= A[i];
        }
        return result;
	}
};

int main()
{
	int A[9] = {-2, -3, -2};
	Solution solution;
	printf("solution=%d\n", solution.singleNumber(A, 9));
	return 1;
}
