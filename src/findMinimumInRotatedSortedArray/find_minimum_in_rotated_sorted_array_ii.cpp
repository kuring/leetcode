#include <stdio.h>
#include <vector>
using namespace std;


class Solution {
public:
    /**
     * 二分查找的变形用法
     * 需要特别注意边界条件的判断
     * 允许存在重复的元素，考虑的情况更加复杂
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
            else if (num[low] == num[high])
            {
                low++;
            }
            else
            {
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
                    low = middle + 1;
                }
            }
        }
        return num[low];
    }
};

int main()
{
    int arr[] = {2,2,2,0,0,1};
    vector<int> num(arr, arr + sizeof(arr) / sizeof(int));
    Solution solution;
    printf("result=%d\n", solution.findMin(num));}
