#include <iostream>
#include <string>

using namespace std;

// so easy
int titleToNumber(string s)
{
    if (s == "")
    {
        return 0;
    }

    int result = 0;
    int tmp = 1;
    for (int i = (int)s.length() - 1; i >= 0; i--)
    {
        result += (s[i] - 'A' + 1) * tmp;
        tmp *= 26;
    }
    return result;
}

int main()
{
    cout << titleToNumber("AB") << endl;
    return 1;
}
