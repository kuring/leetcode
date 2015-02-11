#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 动态规划算法
    // 设f(i,j)表示从(1,1)到(i,j)之间的步骤数
    // f(i,j)=f(i,j-1)+f(i-1,j)，其中f(1,1)=1
    int uniquePaths(int m, int n) {
        vector<vector<int> > f = vector<vector<int> >(m, vector<int>(n, 1));
        for (int i=1; i<m; i++)
        {
            for (int j=1; j<n; j++)
            {
                f[i][j] = f[i-1][j] + f[i][j-1];
            }
        }
        return f[m-1][n-1];
    }
};

int main()
{
    Solution solution;
    cout << solution.uniquePaths(4, 4) << endl;
    return 0;
}