#include <stdio.h>

class Solution {
    public:
        double pow(double x, int n) {
            bool flag = false;
            if (n == 0)
            {
                return 1;
            }

            if (n < 0)
            {
                // 当n为负值的情况下，需要取x的n的负值的次方的倒数
                n = -n;
                flag = true;
            }

            // 求x的n次方
            // 为了避免采用循环乘法的方式，采用了左移操作来代替乘法操作
            // 为了减少乘法的次数，采用了n为偶数x^n = x^n/2 * x^n/2，如果n为奇数x^n = x^n/2 * x^n/2 × x的方式
            double result;
            if (n & 1)
            {
                // 奇数
                result = pow(x, n / 2);
                result *= result;
                result *= x;
            }
            else
            {
                // 偶数
                result = pow(x, n / 2);
                result *= result;
            }
            return flag ? 1 / result : result;
        }
};

int main()
{
    Solution solution;
    printf("%f\n", solution.pow(2, 3));
    return 1;
}
