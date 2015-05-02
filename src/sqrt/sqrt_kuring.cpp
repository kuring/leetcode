#include <string>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 二分搜索法，需要注意边界的处理，这里还用到了last变量，这个也是需要注意的
 */
int mySqrt(int x)
{
    if (x < 2)
    {
        return x;
    }
    int left = 1;
    int right = x / 2;
    int last = 0;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;
        if (x / middle > middle)
        {
            last = middle;
            left = middle + 1;
        }
        else if (x / middle < middle)
        {
            right = middle - 1;
        }
        else
        {
            return middle;
        }
    }

    return last;
}

int main()
{
    mySqrt(2);
    for (int i = 0; i < 101; i++)
    {
        cout << "sqrt " << i << " = " << mySqrt(i) << endl;
    }
    return 1;
}
