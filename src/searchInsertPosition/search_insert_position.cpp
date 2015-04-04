#include <iostream>
using namespace std;

/**
 * 实在太简单了，没有比这个更简单的题了
 */
int searchInsert(int A[], int n, int target)
{
    for (int i=0; i<n; i++)
    {
        if (A[i] == target)
        {
            return i;
        }
        if (A[i] > target)
        {
            return i;
        }
    }
    return n;
}

int main()
{
    int A[] = {1, 3, 5, 6};
    cout << searchInsert(A, sizeof(A)/ sizeof(int), 0);
}
