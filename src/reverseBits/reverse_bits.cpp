#include <string>
#include <iostream>
#include <vector>
#include <inttypes.h>

using namespace std;

void print(uint32_t n)
{
    for (int i=0; i<32; i++)
    {
        if ((n & 0x80000000) != 0)
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
        n = n << 1;
    }
}

/**
 * 移位注意事项：无符号数>>操作左边插入0，有符号数左边插入不确定
 * 比较简单
 */
uint32_t reverseBits(uint32_t n)
{
    uint32_t result = 0;
    for (int i=0; i<32; i++)
    {
        if ((n & 0x80000000) != 0)
        {
            result = result | 0x80000000;
        }
        if (i != 31)
        {
            result = result >> 1;
            n = n << 1;
        }
    }
    return result;
}

int main()
{
    cout << reverseBits(43261596) << endl;
    return 1;
}
