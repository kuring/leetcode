#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int> &num, int begin, int end, int target)
{
    vector<vector<int> > result;
    if (end - begin < 2)
    {
        return result;
    }

    int left = begin;
    while (left < end - 1)
    {
        // 对于值相同的节点直接跳过，避免出现重复的结果
        if (left > begin && num[left] == num[left - 1])
        {
            left++;
            continue;
        }
        int middle = left + 1;
        int right = end;
        while (middle < right)
        {
            if (num[left] + num[middle] + num[right] < target)
            {
                middle++;
            }
            else if (num[left] + num[middle] + num[right] > target)
            {
                right--;
            }
            else
            {
                vector<int> v;
                v.push_back(num[left]);
                v.push_back(num[middle]);
                v.push_back(num[right]);
                result.push_back(v);
                middle++;
                right--;

                // 对于值相同的节点直接跳过，避免出现重复的结果
                while (middle < right && num[middle] == num[middle - 1])
                    middle++;
                
                // 对于值相同的节点直接跳过，避免出现重复的结果
                while (middle < right && num[right] == num[right + 1])
                    right--;
            }
        }
        left++;
    }
    return result;
}

/**
 * 参照网上的算法，先对数组进行排序，然后逐个节点从开头和结尾位置搜索合适的节点集合
 * 时间复杂度为O(n^2 * logn),空间复杂度为O(1)
 */
vector<vector<int> > threeSum(vector<int> &num)
{
    // 先排序
    vector<vector<int> > result;
    if (num.size() < 3)
    {
        return result;
    }
    sort(num.begin(), num.end());
    result = threeSum(num, 0, num.size() - 1, 0);
    return result;
}


int main()
{
//    int A[] = {-15,10,0,-2,14,-1,-10,-14,10,12,6,-6,10,2,-11,-9,2,13,2,-9,-14,-12,-10,-12,13,13,-10,-3,2,-11,3,-6,6,10,7,5,-13,4,-2,12,1,-11,14,-4,6,-12,-6,-14,8,11,-8,1,7,-3,5,5,-13,10,9,-3,6,-10,6,-3,7,-9,-13,9,10,0,-1,-11,4,-10,-8,-13,-15,2,-12,8,-2,-12,-14,-10,-8,6,2,-5,-7,-11,7,14,-6,-10,-12,8,-4,-10,-5,14,-3,9,-12,8,14,-13};
    int A[] = {0, 0, 0};
    vector<int> num(A, A + sizeof(A) / sizeof(int));
    vector<vector<int> > result = threeSum(num);
    for (int i=0; i<(int)result.size(); i++)
    {
        for (int j=0; j<(int)result[i].size(); j++)
        {
            cout << result[i][j] << '\t';
        }
        cout << endl;
    }
    return 1;
}
