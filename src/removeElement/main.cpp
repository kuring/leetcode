#include <stdio.h>

class Solution {

public:
    int removeElement(int A[], int n, int elem) {
		int site = 0;
        for (int i=0; i<n; i++)
		{
			if (A[i] != elem)
			{
				A[site++] = A[i];
			}
		}
		return site;
    }
};

int main()
{
	int arr[10] = {2, 4, 5, 7, 9, 3, 4, 6, 8, 9};
	Solution solution;
	int count = solution.removeElement(arr, 10, 4);
	

	for (int i=0; i<count; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
