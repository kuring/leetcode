#include <iostream>
#include <stdio.h>
using namespace std;

/**
 * 最大连续子数组的乘积，最大连续子数组问题的变形，仍然可以用动态规划进行求解
 * 考虑到负负得正的特性，设Max[i]为以i为结尾的数组的最大乘积，Min[i]为以i为结尾的连续数组的最小乘积，则
 * 当A[i] > 0时，Max[i] = max(Max[i - 1] * A[i], A[i]) ,Min[i] = min(Min[i - 1] * A[i], A[i])
 * 当A[i] < 0时，Max[i] = max(Min[i - 1] * A[i], A[i]), Max[i] = min(Max[i - 1] * A[i], A[i])
 * 该题是动态规划的简略形式，省略了Max和Min数组，使用max_product和min_product来代替，执行效果不变
 *
 * 目前仅发现动态规划一种解题思路
 */
class Solution {
public:
    int maxProduct(int A[], int n) {
        int max_product = A[0];
        int min_product = A[0];
        int max_all = A[0];
        
        for (int i=1; i<n; i++)
        {
            if (A[i] > 0)
            {
                max_product = max(max_product * A[i], A[i]);
                min_product = min(min_product * A[i], A[i]);
            }
            else
            {
                int tmp = max_product;
                max_product = max(min_product * A[i], A[i]);
                min_product = min(tmp * A[i], A[i]);
            }
            max_all = max(max_all, max_product);
        }
        return max_all;
    }
};

int main()
{
    int A[] = {2, 3, -2, 4};
    Solution solution;
    cout << solution.maxProduct(A, sizeof(A)/ sizeof(int)) << endl;
}
