#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool containsDuplicate(vector<int>& nums)
{
	set<int> cache;
	for (auto i : nums)
	{
		if (cache.find(i) != cache.end())
		{
			return true;
		}
		else
		{
			cache.insert(i);
		}
	}
	return false;
}

int main()
{
	vector<int> nums = {1,2,3,4};
	cout << containsDuplicate(nums) << endl;
}
