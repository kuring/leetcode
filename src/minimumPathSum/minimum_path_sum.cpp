#include <string>
#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int>>& grid, size_t row, size_t column, size_t m, size_t n, vector<vector<int> > &cache)
{
    cout << "m=" << m << "n=" << n << endl;
    if (m >= row && n >= column)
    {
        return grid[m][n];
    }

    if (cache[m][n] != -1)
    {
        return cache[m][n];
    }

    int result;
    if (m >= row)
    {
        result = minPathSum(grid, row, column, m, n + 1, cache) + grid[m][n];
    }
    else if (n >= column)
    {
        result = minPathSum(grid, row, column, m + 1, n, cache) + grid[m][n];
    }
    else
    {
        result = min(minPathSum(grid, row, column, m + 1, n, cache), minPathSum(grid, row, column, m, n + 1, cache)) + grid[m][n];
    }
    cache[m][n] = result;
    return result;
}

/**
 * 深度优先搜索法，并使用缓存保存结果，减少不必要循环
 */
int minPathSum(vector<vector<int>>& grid)
{
    size_t row = grid.size();
    if (row == 0)
    {
        return 0;
    }
    size_t column = grid[0].size();
    if (column == 0)
    {
        return 0;
    }

    vector<vector<int> > result(row, vector<int>(column, -1));
    return minPathSum(grid, row - 1, column - 1, 0, 0, result);
}

int main()
{
    vector<vector<int> > result = {{1,2}, {5,6}, {1,1}};
    cout << minPathSum(result) << endl;
    return 1;
}
