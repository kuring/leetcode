#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

// 需要找到规律，并写出程序，需要注意程序溢出的情况
int trailingZeroes(int n) 
{
    if (n <= 0)
    {
        return 0;
    }

    // 此处需要将该变量设置为8个字节，防止溢出时出现死循环情况
    long long tmp = 5;
    int other = 0;
    while (n >= tmp && tmp <= INT_MAX)
    {
        other += n / tmp;
        tmp *= 5;
    }
    
    return other;
}

int main()
{
    cout << trailingZeroes(2147483647) << endl;
    cout << INT_MAX << endl;
    return 1;
}
