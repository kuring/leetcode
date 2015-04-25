#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 采用了用字符串模拟乘法操作的方式，思路上还是比较简单的，很多边界的情况需要注意
 * 还有利用int数组的方式来存储，利用数字的乘法操作来分步完成的思路，没仔细研究
 */
string multiply(string num1, string num2)
{
    string result;
    int begin = 0;
    // 倒序取数，保证从个位开始乘
    for (auto i = num1.rbegin(); i != num1.rend(); i++)
    {
        char carry = 0;
        int step = 0;
        for (auto j = num2.rbegin(); j != num2.rend(); j++)
        {
            short tmp = (*i - '0') * (*j - '0');
            if ((int)result.length() <= begin + step)
            {
                // 不存在该位
                char residue = tmp % 10;
                result.insert(size_t(begin + step), 1, (char)(residue + carry) % 10 + '0');
                carry = (char)(tmp + carry) / 10;
            }
            else
            {
                // 已经存在该位
                char value = (char)tmp + (char)carry + result[size_t(begin + step)] - '0';
                result[size_t(begin + step)] = value % 10 + '0';
                carry = value / 10;
            }
            step++;
        }
        if (carry > 0)
        {
            char tmp = carry + '0';
            result += tmp;
        }
        begin++;
    }
    // 去除字符串多余的零
    for (auto iter = result.end() - 1; iter != result.begin();)
    {
        if (*iter == '0')
        {
            result.erase(iter--);
        }
        else
        {
            break;
        }
    }
    reverse(result.begin(), result.end());
    return result;    
}

int main()
{
    cout << multiply("98", "0") << endl;
    return 1;
}
