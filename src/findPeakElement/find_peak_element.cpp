#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

/**
 * 本题非常简单，只要注意逻辑即可
 * 时间复杂度O(n)，空间复杂度O(1)
 */
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        if (num.size() == 0)
        {
           return -1; 
        }
        if (num.size() > 1)
        {
            if (num[0] > num[1])
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
        for (int i=1; i<(int)num.size(); i++)
        {
            if (num[i] <= num[i - 1])
            {
                continue;
            }
            if ((int)num.size() > (i + 1))
            {
                if (num[i] > num[i + 1])
                {
                    return i;
                }
            }
            else
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    int arr[] = {1, 2, 3};
    vector<int> num(arr, arr + sizeof(arr) / sizeof(int));
    Solution solution;
    cout << solution.findPeakElement(num) << endl;
    return 1;
}
