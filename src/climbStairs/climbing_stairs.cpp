#include <iostream>
#include <string.h>
using namespace std;

/**
 * f(n) = f(n - 1) + f(n - 2),f(1)=1,f(2)=2
 * 直接使用递归算法会提示超时
 * 可以通过循环方式代替递归方式，我这里申请的数组，其实完全可以不用申请数组，用三个变量就可以搞定了
 */
int climbStairs(int n)
{
    int *p = new int[n + 1];
    memset(p, 0, sizeof(int) * n);
    p[1] = 1;
    p[2] = 2;
    int i = 3;
    while (i <= n)
    {
        p[i] = p[i-1] + p[i-2];
        i++;
    }
    int result = p[n];
    delete[] p;
    return result;
}

int main()
{
    cout << climbStairs(6) << endl;
    return 1;
}
