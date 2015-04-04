#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_contain(vector<vector<int> > &result, int num1, int num2)
{
    for (int i=0; i<(int)result.size(); i++)
    {
        bool b1 = false, b2 = false;
        for (int j=0; j<(int)result[i].size(); j++)
        {
            if (result[i][j] == num1)
            {
                b1 = true;
            }
            if (result[i][j] == num2)
            {
                b2 = true;
            }
        }
        if (b1 && b2)
        {
            return true;
        }
    }
    return false;    
}

/**
 * 时间复杂度较高，系统提示Time Limit Exceeded
 */
vector<vector<int> > threeSum(vector<int> &num)
{
    vector<vector<int> > result;
    for (int i=0; i<(int)num.size(); i++)
    {
        for (int j=i+1; j<(int)num.size(); j++)
        {
            // 判断解是否已经在集合中了
            if (is_contain(result, num[i], num[j]))
            {
                continue;
            }
            for (int k=j+1; k<(int)num.size(); k++)
            {
                if (num[i] + num[j] + num[k] == 0)
                {
                    // 将结果排序后放入结果集中
                    vector<int> v;
                    v.push_back(num[i]);
                    v.push_back(num[j]);
                    v.push_back(num[k]);
                    sort(v.begin(), v.end());
                    result.push_back(v);
                }
            }
        }
    }
    return result;
}


int main()
{
    int A[] = {-15,10,0,-2,14,-1,-10,-14,10,12,6,-6,10,2,-11,-9,2,13,2,-9,-14,-12,-10,-12,13,13,-10,-3,2,-11,3,-6,6,10,7,5,-13,4,-2,12,1,-11,14,-4,6,-12,-6,-14,8,11,-8,1,7,-3,5,5,-13,10,9,-3,6,-10,6,-3,7,-9,-13,9,10,0,-1,-11,4,-10,-8,-13,-15,2,-12,8,-2,-12,-14,-10,-8,6,2,-5,-7,-11,7,14,-6,-10,-12,8,-4,-10,-5,14,-3,9,-12,8,14,-13};
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
