#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 动态规划算法
    // 设f(i,j)表示从(1,1)到(i,j)之间的步骤数
    // f(i,j)=f(i,j-1)+f(i-1,j)，其中f(0,0)=1
	// f(i,j)=0,当obstacleGrid[i][j]=1时
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        vector<vector<int> > f = vector<vector<int> >(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
		if (obstacleGrid[0][0] == 1)
		{
			f[0][0] = 0;
		}
		else
		{
			f[0][0] = 1;
		}
		
		for (int i=1; i<obstacleGrid.size(); i++)
		{
			if (obstacleGrid[i][0] == 1)
			{
				f[i][0] = 0;
			}
			else
			{
				f[i][0] = f[i-1][0];
			}
		}
		for (int i=1; i<obstacleGrid[0].size(); i++)
		{
			if (obstacleGrid[0][i] == 1)
			{
				f[0][i] = 0;
			}
			else
			{
				f[0][i] = f[0][i-1];
			}
		}
		
        for (int i=1; i<obstacleGrid.size(); i++)
        {
            for (int j=1; j<obstacleGrid[i].size(); j++)
            {
				if (obstacleGrid[i][j] == 1)
				{
					f[i][j] = 0;
				}
				else
				{
					f[i][j] = f[i-1][j] + f[i][j-1];
				}                
            }
        }
        return f[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};

int main()
{
	vector<vector<int> > obstacleGrid = vector<vector<int> >(3, vector<int>(2, 0));
	obstacleGrid[1][0] = 1;
	obstacleGrid[1][1] = 1;
	
    Solution solution;
    cout << solution.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}