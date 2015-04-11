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
 * 面试题中经常遇到的求二进制中1个数的思路
 * 另外，还有一种Hamming weight的思路，我这里并没有写出，因为即使现在明白了，之后也会忘记，不如等到用到时再去查
 */
int hammingWeight(uint32_t n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main()
{
    cout << hammingWeight(43261596) << endl;
    return 1;
}
