#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 参照网上的算法，先对数组进行排序，然后逐个节点从开头和结尾位置搜索合适的节点集合
 */
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
                while (middle < right && num[middle] == num[middle - 1])
                    middle++;
                middle++;
            }
            else if (num[left] + num[middle] + num[right] > target)
            {
                while (middle < right && num[right] == num[right + 1])
                    right--;
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
 * 直接调用3Sum，时间复杂度为O(n^3 * logn)，空间复杂度为O(1)
 */
vector<vector<int> > fourSum(vector<int> &num)
{
    vector<vector<int> > result;
    sort(num.begin(), num.end());
    for (int i=0; i<(int)num.size(); i++)
    {
        if (i > 0 && num[i] == num[i-1])
        {
            continue;
        }
        // 调用3Sum的算法
        vector<vector<int> > r = threeSum(num, i + 1, num.size() - 1, 0 - num[i]); 
        for (int j=0; j<(int)r.size(); j++)
        {
            vector<int> tmp = r[j];
            tmp.insert(tmp.begin(), num[i]);
            result.push_back(tmp);
        }
    }
    return result;
}


int main()
{
    int A[] = {1, 0, -1, 0, -2, 2};
    vector<int> num(A, A + sizeof(A) / sizeof(int));
    vector<vector<int> > result = fourSum(num);
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
