#include <string>
#include <iostream>
#include <vector>

using namespace std;

void subsets(int start, vector<int> &nums, vector<int> value, vector<vector<int>> &result)
{
	// 将结果放入集合中
	result.push_back(value);
	
	for (int i = start; i < nums.size(); i++)
	{
		auto tmp = value;
		tmp.push_back(nums[i]);
		subsets(i + 1, nums, tmp, result);
	}
}

/**
 * 使用递归方式实现
 */
vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> result;
	if (nums.size() > 0)
	{
		sort(nums.begin(), nums.end());
		subsets(0, nums, {}, result);
	}
	else
	{
		result.push_back({});
	}
	return result;
}

int main()
{
	vector<int> nums = {1, 2, 3};
    vector<vector<int> > result = subsets(nums);
    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 1;
}