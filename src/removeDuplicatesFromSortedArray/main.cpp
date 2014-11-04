#include <stdio.h>

class Solution {

public:
	int removeDuplicates(int A[], int n)
	{
		if (n <= 0)
		{
			return 0;
		}
		int site = 0;
        for (int i=1; i<n; i++)
		{
			if (A[i] != A[site])
			{
				A[++site] = A[i];
			}
		}
		return site + 1;

    }
};

int main()
{
	Solution solution;
	int arr[10] = {2, 2, 3, 4, 4, 5, 6, 6, 8, 9};
	int count = solution.removeDuplicates(arr, 10);
	for (int i=0; i<count; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	
	int arr2[1] = {2};
	count = solution.removeDuplicates(arr2, 1);
	for (int i=0; i<count; i++)
	{
		printf("%d\t", arr2[i]);
	}
	printf("\n");
}
