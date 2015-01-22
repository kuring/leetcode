#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<int> solution(n);
		vector<vector<string> > result;
		recursive(n, solution, 0, result);
		return result;
	}
	
	// 递归算法解决n皇后问题
	// 递归所有的解空间，如果通过循环实现会非常麻烦，循环容易实现复杂度为O(n^2)的情况，递归容易实现复杂度为)(n^n)的情况
	// 该问题要遍历所有的解空间，时间复杂度为(n^n)
	// 在遍历的过程中一旦发现该解不合适即该解停止后面的循环工作
	void recursive(int n, vector<int> solution, int current_row, vector<vector<string> > &result)
	{
		for (int i=0; i<n; i++)
		{
			if (check(solution, current_row, i))
			{
				solution[current_row] = i;
				if (current_row == n - 1)
				{
					result.push_back(get_result(solution, n));
				}
				recursive(n, solution, current_row + 1, result);
			}
		}
	}
	
	// 根据一个结果获取要返回的字符串集合格式
	vector<string> get_result(vector<int> solution, int n)
	{
		vector<string> result;
		for (int i=0; i<solution.size(); i++)
		{
			string tmp;
			for (int j=0; j<n; j++)
			{
				if (solution[i] == j)
				{
					tmp += "Q";
				}
				else
				{
					tmp += ".";
				}
			}
			result.push_back(tmp);
		}
		return result;
	}
	
	// 检查current_row行col列的值是否满足条件
	bool check(vector<int> &solution, int current_row, int col)
	{
		for (int i=0; i<current_row; i++)
		{
			if (solution[i] == col)
			{
				return false;
			}
			if (abs(current_row - i) == abs(solution[i] - col))
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	Solution solution;
	vector<vector<string> > result = solution.solveNQueens(8);
	printf("find %d result\n", result.size());
	for (int i=0; i<result.size(); i++)
	{
		for (int j=0; j<result[i].size(); j++)
		{
			printf("%s\n", result[i][j].c_str());
		}
		printf("\n");
	}
	return 1;
}