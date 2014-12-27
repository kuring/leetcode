#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
	// f(i,j)=min(f(i,j+1),f(i+1,j+1)) + f(i,j)
	int minimumTotal (vector< vector<int> >& triangle) {
		for (int j=(int)triangle.size() - 2; j>=0; j--)
		{
			for (int i=0; i<=(int)triangle[j].size() - 1; i++)
			{
				triangle[j][i] += min(triangle[j+1][i], triangle[j+1][i+1]);
			}
		}
		return triangle[0][0];
	}
};

int main()
{

	int arr[4][4] = {
		{2, 0, 0, 0},
		{3, 4, 0, 0},
		{6, 5, 7, 0},
		{4, 1, 8, 3}
	};
	vector< vector<int> > triangle;
	for (int i=0; i<4; i++)
	{
		vector<int> tmp;
		for (int j=0; j<4; j++)
		{
			tmp.push_back(arr[i][j]);
		}
		triangle.push_back(tmp);
	}
/*	
	vector< vector<int> > triangle;
	vector<int> ints;
	ints.push_back(1);
	triangle.push_back(ints);
	
	ints.clear();
	ints.push_back(2);
	ints.push_back(3);
	triangle.push_back(ints);*/
	
	Solution solution;
	printf("%d\n", solution.minimumTotal(triangle));
}