#include <string>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

/**
 * 比较简单
 * 为了防止死循环的出现，这里使用set来保存之前已经计算过的数，当发现死循环时直接返回false
 */
bool isHappy(int n)
{
    if (n <= 0)
    {
        return false;
    }
    int number  = n;
    set<int> number_set;
    number_set.insert(number);
    while (number != 1)
    {
        int value = 0;
        while (number > 0)
        {
            int tmp  = number % 10;
            value += tmp * tmp;
            number = number / 10;
        }
        if (value == 1)
        {
            return true;
        }
        number = value;
        if (number_set.find(number) != number_set.end())
        {
            return false;
        }
        else
        {
            number_set.insert(number);
        }
    }
    return true;
}

int main()
{
    cout << isHappy(1) << endl;
    return 1;
}
