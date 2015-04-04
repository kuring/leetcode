#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

/**
 * 跟3sum算法一致
 */
int threeSumClosest(vector<int> &num, int target)
{
    // 先排序
    if (num.size() < 3)
    {
        return -1;
    }
    sort(num.begin(), num.end());

    int result;
    bool is_result_init = false;
    int left = 0;
    while (left < (int)num.size() - 2)
    {
        // 对于值相同的节点直接跳过，避免重复计算
        if (left > 0 && num[left] == num[left - 1])
        {
            left++;
            continue;
        }
        int middle = left + 1;
        int right = num.size() - 1;
        while (middle < right)
        {
            int sum = num[left] + num[middle] + num[right]; 
            if (sum < target)
            {
                middle++;
                while (middle < right && num[middle] == num[middle - 1])
                    middle++;
            }
            else if (sum > target)
            {
                right--;
                while (middle < right && num[right] == num[right + 1])
                    right--;
            }
            else
            {
                return target;
            }
            if (!is_result_init || (is_result_init && abs(result - target) > abs(sum - target)))
            {
                result = sum;
                is_result_init = true;
            }
        }
        left++;
    }
    return result;
}


int main()
{
    int A[] = {1, 1, 1, 0};
    vector<int> num(A, A + sizeof(A) / sizeof(int));
    cout << threeSumClosest(num, 1) << endl;;
    return 1;
}
