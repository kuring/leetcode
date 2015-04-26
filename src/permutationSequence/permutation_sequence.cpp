#include <string>
#include <iostream>
#include <vector>

using namespace std;

string getPermutation(int n, int k, string &str)
{
    cout << "n=" << n << " k=" << k << " str=" << str << endl;
    if (k == 1 || str.length() == 1)
    {
        return str;
    }
    int number = 1;
    for (int i=1; i<n; i++)
    {
        number *= i;
    }
    string result;
    int site = (k - 1) / number;
    result += str[site];
    str.erase(site, 1);

    if (site != 0)
    {
        k = (k - 1) % number + 1;
    }
    result += getPermutation(n - 1, k, str);
    return result;
}

/**
 * 采用递归方式实现，需要找到规律
 * 貌似该种算法就是康托编码
 */
string getPermutation(int n, int k)
{
    string str;
    if (n <= 0 && k < 0)
    {
        return str;
    }
    for (int i=1; i<=n; i++)
    {
        str += (char)(i + '0');
    }

    return getPermutation(n, k, str);
}

int main()
{
    cout << getPermutation(4, 7) << endl;
    return 1;
}
