#include <string>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 采用动态规划思路完成，用贪心算法是不合适的，比如7,8,7用贪心算法得到的结果为8，而结果应该为14
 * f(n) = max(f(n-1), f(n-2) + nums[i])
 * 代码中的max_vector可以优化为用两个变量，这里不再做优化处理 
 */
int rob(vector<int>& nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    else if (nums.size() == 1)
    {
        return nums[0];
    }

    vector<int> max_vector(nums.size(), 0);
    max_vector[0] = nums[0];
    max_vector[1] = max(nums[0], nums[1]);
    for (size_t i = 2; i < nums.size(); i++)
    {
        max_vector[i] = max(max_vector[i - 1], max_vector[i - 2] + nums[i]);
    }
    
    return max_vector[nums.size() - 1];
}

int main()
{
    vector<int> nums = {4, 5, 7, 9, 3, 6};
    cout << rob(nums) << endl;
    return 1;
}
