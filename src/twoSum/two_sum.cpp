#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		map<int, int> m;
		vector<int> result;
		// 通过map建立数值和下标之间的对应关系
		for (int i=0; i<numbers.size(); i++)
		{
			m[numbers[i]] = i;
		}
		for (int i=0; i<numbers.size(); i++)
		{
			if (m.find(target - numbers[i]) != m.end() && m[target - numbers[i]] != i)
			{
				result.push_back(min(i, m[target - numbers[i]]) + 1);
				result.push_back(max(i, m[target - numbers[i]]) + 1);
				return result;
			}
		}
		return result;
    }
};

int main()
{
	int num[] = {0, 4, 3, 0};
	vector<int> numbers(num, num + sizeof(num) / sizeof(int));
    Solution solution;
	vector<int> result = solution.twoSum(numbers, 0);
	for (int i=0; i<result.size(); i++)
	{
		cout << result[i] << "\t";
	}
    cout << endl;
    return 0;
}