#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permute(vector<int> &num, vector<int> &solution, vector<vector<int> > &result)
{
    if (solution.size() == num.size())
    {
        result.push_back(solution);
        return ;
    }
    bool is_have = false;
    for (size_t i = 0; i < num.size(); i++)
    {
        vector<int>::iterator iter = find(solution.begin(), solution.end(), num[i]);
        if (iter != solution.end())
        {
            continue;
        }
        is_have = true;
        solution.push_back(num[i]);
        permute(num, solution, result);
        solution.pop_back();
    }

    if (is_have == false)
    {
        result.push_back(solution);
    }
}


/**
 * 看到排列问题最简单的解决办法就是递归
 * 可直接调用STL中的std::next_permutation函数
 */
vector<vector<int> > permute(vector<int> &num)
{
    vector<vector<int> > result;
    if (num.size() <= 0)
    {
        return result;
    }

    vector<int> solution;
    permute(num, solution, result);
    return result;
}

int main()
{
    int arr[] = {1, 2, 3};
    vector<int> num(arr, arr + sizeof(arr) / sizeof(int));
    vector<vector<int> > result = permute(num);
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
