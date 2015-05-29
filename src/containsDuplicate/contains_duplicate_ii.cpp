#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	map<int, int> cache;
	for (size_t i = 0; i < nums.size(); i++)
	{
		auto site = cache.find(nums[i]);
		if (site != cache.end())
		{
			if (i - site->second <= k)
			{
				return true;
			}
			else
			{
				cache[nums[i]] = i;
			}
		}
		else
		{
			cache[nums[i]] = i;
		}
	}
	return false;
}

int main()
{
	vector<int> nums = {1,2,3,4,9,6,7,8};
	cout << containsNearbyDuplicate(nums, 4) << endl;
}
