#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <stdarg.h>
#include <vector>

/**
 * 花费了半个小时的代码居然调试了接近两个小时，各种测试通不过
 */
class Solution {
public:
    int compare_array[4];

    int maxSubArray(int A[], int n) {
        return maxSubArray(A, 0, n - 1);
    }

    /**
     * leetcode not support stdarg.h
     */
    int max(int count, ...)
    {
        va_list ap;
        va_start(ap, count);
        int max = INT_MIN;
        for (int i=0; i<count; i++)
        {
            int temp = va_arg(ap, int);
            if (max < temp)
            {
                max = temp;
            }
        }
        va_end(ap);
        return max;
    }

    int max_compare_array()
    {
        int max_num = compare_array[0];
        for (int i=1; i<4; i++)
        {
            if (max_num < compare_array[i])
            {
                max_num = compare_array[i];
            }
        }
        return max_num;
    }

    int maxSubArray(int A[], int begin, int end)
    {
        //printf("begin : %d, end : %d\n", begin, end);
        if (begin == end)
        {
            return A[begin];
        }
        else if ((end - begin) == 1)
        {
            //return max(3, A[begin], A[begin] + A[end], A[end]);
            compare_array[0] = A[begin];
            compare_array[1] = A[begin] + A[end];
            compare_array[2] = A[end];
            compare_array[3] = INT_MIN;
            return max_compare_array();
        }
        int middle = (begin + end) / 2;
        // 处理左边子数组
        int max_left = maxSubArray(A, begin, middle);
        // 处理右边子数组
        int max_right = maxSubArray(A, middle + 1, end);
        // 处理跨越中点的情况
        int max_cross = maxCrossMiddle(A, begin, end);

        printf("begin : %d, end : %d, max_left = %d, max_right = %d, max_cross = %d\n", begin, end, max_left, max_right, max_cross);

        // 返回三者中的最大值
        compare_array[0] = max_left;
        compare_array[1] = max_right;
        compare_array[2] = max_cross;
        compare_array[3] = INT_MIN;
        return max_compare_array();
    }

    /**
     * 处理跨越中点的情况
     */
    int maxCrossMiddle(int A[], int begin, int end)
    {
        if (begin == end)
        {
            return A[begin];
        }
        int middle = (begin + end) / 2;
        // 求得[begin -- middle-1]的最大值
        int max_left = A[middle - 1];
        int sum = 0;
        for (int i=middle - 1; i>=begin && i >= 0; i--)
        {
            sum += A[i];
            if (max_left < sum)
            {
                max_left = sum;
            }
        }

        // 求得[middle+1 -- end]的最大值
        int max_right = A[middle + 1];
        sum = 0;
        for (int i=middle + 1; i<=end; i++)
        {
            sum += A[i];
            if (max_right< sum)
            {
                max_right = sum;
            }
        }

        compare_array[0] = A[middle];
        compare_array[1] = A[middle] + max_left;
        compare_array[2] = A[middle] + max_right;
        compare_array[3] = A[middle] + max_left + max_right;
        return max_compare_array();
    }
};


int main()
{
    // int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int A[] = {3, 0, 0, 2, 2};
    Solution solution;
    printf("result = %d\n", solution.maxSubArray(A, sizeof(A) / sizeof(int)));
    return 1;
}
