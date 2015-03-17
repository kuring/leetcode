#include <string>
#include <iostream>
using namespace std;

/**
 * 针对该问题可以通过乘法的思路来解决，执行效率并不低
 * 我这里采用了逐位比较字符串的方式，牵涉到字符0和小数点的处理，主要是对于string的erase操作，执行效率并不是很高
 */
class Solution {
public:
    int compareVersion(string version1, string version2) {
        do
        {
            string int1 = version1.substr(0, version1.find('.'));
            string int2 = version2.substr(0, version2.find('.'));
            int result = compareNumber(int1, int2);
            if (result != 0)
            {
                return result;
            }
            
            if (version1.find('.') != string::npos)
            {
                version1 = version1.substr(version1.find('.') + 1, version1.length() - version1.find('.'));
            }
            else
            {
                version1 = "";
            }

            if (version2.find('.') != string::npos)
            {
                version2 = version2.substr(version2.find('.') + 1, version2.length() - version2.find('.'));
            }
            else
            {
                version2 = "";
            }
        }
        while (version1 != "" && version2 != "");

        if (version1 != "")
        {
            trim_from_left_0(version1);
        }
        else
        {
            trim_from_left_0(version2);
        }
        return compareNumber(version1, version2);
    }

    int compareNumber(string num1, string num2)
    {
        trim_left_0(num1);
        trim_left_0(num2);
        if (num1.length() != num2.length())
        {
            return num1.length() > num2.length() ? 1 : -1;
        }

        if (num1 != num2)
        {
            return num1 > num2 ? 1 : -1;
        }
        return 0;
    }

    void trim_left_0(string &str)
    {
        while (str[0] == '0')
        {
            str.erase(0, 1);
        }
    }

    void trim_from_left_0(string &str)
    {
        while (str[0] == '0' || str[0] == '.')
        {
            str.erase(0, 1);
        }
    }
};

int main()
{
    Solution solution;
    cout << solution.compareVersion("19.8.3.17.5.01.0.0.4.0", "19.8.3.17.5.01.0.0.4.0.0.0.0") << endl;
    return 1;
}
