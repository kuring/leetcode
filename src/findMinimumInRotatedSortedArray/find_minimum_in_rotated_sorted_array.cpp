#include <stdio.h>
#include <vector>
using namespace std;


class Solution {
public:
    /**
     * 二分查找的变形用法
     * 需要特别注意边界条件的判断
     */
    int findMin(vector<int> &num) {
        if (num.size() == 0)
        {
            return -1;
        }

        int low = 0, high = num.size() - 1;
        while (low < high)
        {
            if (num[low] < num[high])
            {
                // the rotated array is sorted
                return num[low];
            }
            int middle = (high + low) / 2;
            if (num[middle] > num[low])
            {
                low = middle + 1;
            }
            else if (num[middle] < num[low])
            {
                high = middle;
            }
            else
            {
                return num[low] < num[high] ? num[low] : num[high];
            }
        }
        return num[low];
    }
};

int main()
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    vector<int> num(arr, arr + sizeof(arr) / sizeof(int));
    Solution solution;
    printf("result=%d\n", solution.findMin(num));}
