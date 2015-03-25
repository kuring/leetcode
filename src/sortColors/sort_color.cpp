#include <stdio.h>

/**
 * 本题为特殊的排序算法，要使用通用的排序算法，肯定可以通过nlogn的时间内完成。
 * 要想实现O(n)的时间复杂度，需要利用本题自身的特点，即要排序的数组中仅有三种元素。
 * 本题我仅想到了一种快速排序的变形算法可以实现一遍循环即可完成排序的功能。
 * 我的算法的思想跟陈浩是一致的，我的代码的逻辑复杂程度明显要高很多，可以好的编码思路还是重要的。
 *
 × 如果要将本题的三种元素更改为四中元素则不能使用该算法
 */
class Solution {
public:
    void sortColors(int A[], int n) {
        int left = 0;
        int right = n - 1;
        int first_1 = -1;
        while (left <= right)
        {
            while (first_1 == -1 && A[left] == 0 && left++);
            while (A[right] == 2 && right--);
            if (left >= n || right < 0 || left > right)
            {
                return ;
            }
            if (A[left] == 2)
            {
                A[left] = A[right];
                A[right] = 2;
                right--;
            }
            else if (A[left] == 1)
            {
                if (first_1 == -1)
                {
                    first_1 = left;
                }
                left++;
            }
            else if (first_1 != -1 && A[left] == 0)
            {
                A[first_1] = 0;
                A[left++] = 1;
                for (int i=first_1; i<left; i++)
                {
                    if (A[i] == 1)
                    {
                        first_1 = i;
                        break;
                    }
                }
            }
        }
    }
};

int main()
{
    //int A[] = {0, 0, 2, 2, 1, 0, 0, 1, 1, 0, 2};
    int A[] = {0, 2};
    Solution solution;
    solution.sortColors(A, sizeof(A) / sizeof(int));
    for (int i=0; i<(int)(sizeof(A)/sizeof(int)); i++)
    {
        printf("%d ", A[i]);
    }
    return 1;
}
