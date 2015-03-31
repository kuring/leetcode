#include <stdio.h>
#include <algorithm>
#include <limits.h>

/**
 * 自己没有写出，参照网上代码，解释见博客
 */
class Solution {
public:
	int singleNumber(int A[], int n) {
        int count[32] = {0};
        int result = 0;
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < n; j++) {
                if ((A[j] >> i) & 1) {
                    count[i]++;
                }
            }
            result |= ((count[i] % 3) << i);
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
