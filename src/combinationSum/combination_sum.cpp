#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/**
 * 此处对于solution的处理比较巧妙
 */
void combinationSum(vector<int> &candidates, int start, int target, vector<int> &solution, vector<vector<int> > &result)
{
    if (target < 0)
    {
        // 说明该分支结果不成立
        return ;
    }
    if (target == 0)
    {
        // 找到其中一个解
        result.push_back(solution);
    }
    for (size_t i = start; i < candidates.size(); i++)
    {
        if ((int)i > start && candidates[i] == candidates[i - 1])
        {
            // 当存在相同元素时，不再判断，避免重复结果集
            continue;
        }
        solution.push_back(candidates[i]);
        combinationSum(candidates, i, target - candidates[i], solution, result);
        solution.pop_back();
    }
}

/**
 * 本来想着采用map的方式先缓存所有每个元素的倍数，在对map中的元素进行判断，后来发现采用map的方式也并不简单
 * 参考了haoel的解法，采用dfs解法，思路清晰，代码简洁
 */
vector<vector<int> > combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int> > result;
    if (candidates.size() <= 0)
    {
        return result;
    }
    sort(candidates.begin(), candidates.end());
    vector<int> solution;
    combinationSum(candidates, 0, target, solution, result);
    return result;
}

int main()
{
    int arr[] = {2, 3, 6, 7};
    vector<int> candidates(arr, arr + sizeof(arr) / sizeof(int));
    vector<vector<int> > result = combinationSum(candidates, 7);
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
