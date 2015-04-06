#include <vector>
#include <stdio.h>

using namespace std;

/**
 * 二分查找的变形
 */
class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		int low = 0, high = n - 1;
		while (low <= high)
		{
			int middle = low + (high - low) / 2;
			if (target < A[middle])
			{
				high = middle - 1;
			}
			else if (target > A[middle])
			{
				low = middle + 1;
			}
			else
			{
                // 找到目标，以目标为中心点向左和向右查找边界
				for (int i=0; middle - i >= 0 && A[middle]==A[middle-i]; i++)
				{
					low = middle - i;
				}
				for (int i=0; middle + i < n && A[middle]==A[middle+i]; i++)
				{
					high = middle + i;
				}
				break;
			}
		}
		
		vector<int> result;
		if (low < high)
		{
			result.push_back(low);
			result.push_back(high);
		}
		else if (low == high)
		{
			if (low != 0 && low != n - 1)
			{
				result.push_back(low);
				result.push_back(high);
			}
			else if (low == 0 && target == A[0])
			{
				result.push_back(low);
				result.push_back(high);
			}
			else if (high == n-1 && target == A[n-1])
			{
				result.push_back(low);
				result.push_back(high);
			}
		}
		if (result.size() == 0)
		{
			result.push_back(-1);
			result.push_back(-1);
		}
		return result;
	}
};

int main()
{
	int A[8] = {0, 0, 0, 1, 2, 3};
	Solution solution;
	vector<int> result = solution.searchRange(A, sizeof(A) / sizeof(int), 0);
	printf("%d,%d\n", result[0], result[1]);
}
