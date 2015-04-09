#include <string>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 思路一：
 * 仅翻转一次的函数，如果调用k % n次会超时，该种方案不可行
 *
 * 时间复杂度为O(n * k)，空间复杂度为O(1)
 */
void rotate1(int nums[], int n, int k)
{
    if (k <= 0)
    {
        return ;
    }
    else if (k > n)
    {
        k = k % n;
    }
    for (int i=0; i<k; i++)
    {
        int tail = nums[n - 1];
        for (int i = n - 1; i > 0; i--)
        {
            nums[i] = nums[i - 1];
        }
        nums[0] = tail;
    }
}

/**
 * 思路二：
 * 1.申请k个空间，先将要旋转的k个空间复制到临时数组中
 * 2.将数组中的剩余空间向后复制
 * 3.将临时数组中的内容复制到该数组的前部
 *
 * 时间复杂度为O(n)，空间复杂度为O(k)
 */
void rotate2(int nums[], int n, int k) {
    if (k <= 0)
    {
        return ;
    }
    else if (k > n)
    {
        k = k % n;
    }
    int *nums_temp = new int[k];
    for (int i = n - k, j = 0; i < n && j < k; i++, j++)
    {
        nums_temp[j] = nums[i];
    }

    for (int i = n - k - 1, j = n - 1; i >= 0; i--, j--)
    {
        nums[j] = nums[i];
    }

    for (int i = 0; i < k; i++)
    {
        nums[i] = nums_temp[i];
    }
    delete[] nums_temp;
}

/**
 * 思路三：
 * 假设数组为[1,2,3,4,5,6,7], k=3
 * 1. 将5之前的数据反转 [4,3,2,1,5,6,7]
 * 2. 将5和之后的数据反转 [4,3,2,1,7,6,5]
 * 3. 将数组整体反转 [5,6,7,1,2,3,4]
 *
 * 时间复杂度为O(2n)，空间复杂度为O(1)
 */
void rotate3(int nums[], int n, int k) {
   // 不再写出代码实现 
}
 

int main()
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    rotate3(nums, sizeof(nums) / sizeof(int), 3);
    for (int i = 0; i < (int)(sizeof(nums) / sizeof(int)); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 1;
}
