#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

/**
 * 正向循环，不使用递归方式
 * 思路比较简单
 */
class Solution {
public:
    string countAndSay(int n) {
        if (n == 0)
        {
            return "";
        }
        int count = 1;
        string str = "1";
        while (count < n)
        {
            count++;
            string tmp;
            for (int i=0; i<(int)str.length();)
            {
                int same_count = find_next_count(str[i], str, i + 1);
                char t[4];
                sprintf(t, "%d", same_count + 1);
                tmp += t;
                tmp += str[i];
                i += same_count + 1;
            }
            str = tmp;
        }
        return str;
    }

    int find_next_count(char c, string &str, int begin)
    {
        int count = 0;
        while (begin < (int)str.length() && str[begin] == c)
        {
            count++;
            begin++;
        }
        return count;
    }
};

int main()
{
    Solution solution;
    string result = solution.countAndSay(6);
    cout << result << endl;
}
