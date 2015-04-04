#include <string>
#include <iostream>
using namespace std;

/**
 * 逻辑上稍微啰嗦一点，比较简单，三个while循环可以合并为一个
 */
string addBinary(string a, string b)
{
    string result;
    int i = a.length() - 1;
    int j = b.length() - 1;

    char next = 0;
    while (i >= 0 && j >= 0)
    {
        if (a[i] - '0' + b[j] - '0' + next > 1)
        {
            result.insert(result.begin(), a[i] + b[j] - '0' + next - 2);
            next = 1;
        }
        else
        {
            result.insert(result.begin(), a[i] + b[j] - '0' + next);
            next = 0;
        }
        i--;
        j--;
    }

    while (i >= 0)
    {
        if (a[i] - '0' + next > 1)
        {
            result.insert(result.begin(), a[i] + next - 2);
            next = 1;
        }
        else
        {
            result.insert(result.begin(), a[i] + next);
            next = 0;
        }
        i--;
    }
    while (j >= 0)
    {
        if (b[j] - '0' + next > 1)
        {
            result.insert(result.begin(), b[j] + next - 2);
            next = 1;
        }
        else
        {
            result.insert(result.begin(), b[j] + next);
            next = 0;
        }
        j--;
    }

    if (next == 1)
    {
        result.insert(result.begin(), '0' + next);
    }
    return result;
}

int main()
{
    cout << addBinary("11", "1") << endl;
    return 1;
}
