#include <stdio.h>
#include <iostream>

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int size = m + n - 1;
		int i = m - 1;
		int j = n - 1;
		
		for (int k=size; k>=0 && j>=0 && i>=0; k--)
		{
			if (A[i] >= B[j])
			{
				A[k] = A[i];
				i--;
			}
			else
			{
				A[k] = B[j];
				j--;
			}
		}
		if (i < 0)
		{
			for (int x=j; x>=0; x--)
			{
				A[x] = B[x];
			}
			return ;
		}
    }
};

int main()
{
	int A[20] = {};
	int B[20] = {1};
	Solution solution;
	solution.merge(A, 0, B, 1);
	for (int i=0; i<9; i++)
	{
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
	return 1;
}