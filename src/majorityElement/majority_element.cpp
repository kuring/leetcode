#include <vector>
#include <iostream>
#include <map>
#include <limits.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 哈希实现方式，非常容易想到，时间复杂度为O(n)
    int majorityElement(vector<int> &num) {
        std::map<int, int> result_map;
        for (vector<int>::iterator iter = num.begin(); iter != num.end(); iter++)
        {
            if (result_map.find(*iter) == result_map.end())
            {
                result_map.insert(map<int, int>::value_type(*iter, 1));
            }
            else
            {
                result_map[*iter]++;
            }
        }

        int max_count = 0;
        int result;
        for (std::map<int, int>::iterator iter = result_map.begin(); iter != result_map.end(); iter++)
        {
            if (iter->second > max_count)
            {
                result = iter->first;
                max_count = iter->second;
            }
        }
        return result;
    }

    // 排序法
    // 先排序，排序后的中位数元素必为要求的最多重复数字的个数
    int majorityElementSort(vector<int> &num) {
        sort(num.begin(), num.end());
        return num[num.size() / 2];
    }
};

int main()
{
    int arr[] = {1, 2, 3, 2, 4, 2, 2};
    vector<int> num(arr, arr + sizeof(arr) / sizeof(int));
    Solution solution;
    std::cout << solution.majorityElementSort(num) << std::endl;
    return 1;
}
