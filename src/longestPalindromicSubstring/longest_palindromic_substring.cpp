#include <string>
#include <iostream>

using namespace std;

string get_palindromic(string &s, int site)
{
    string result = s.substr(site, 1);

    // deal "abba"
    int begin = site;
    int end = site + 1;
    while (begin >= 0 && end < (int)s.length())
    {
        if (s[begin] == s[end])
        {
            result = s.substr(begin, end - begin + 1);
            begin--;
            end++;
        }
        else
        {
            break;
        }
    }

    // deal "aba"
    begin = site - 1;
    end = site + 1;
    while (begin >= 0 && end < (int)s.length())
    {
        if (s[begin] == s[end])
        {
            if ((int)result.length() < end - begin + 1)
            {
                result = s.substr(begin, end - begin + 1);
            }
            begin--;
            end++;
        }
        else
        {
            break;
        }
    }
    return result;
}

/**
 *  该解法算法复杂度为O(n^2)
 * 另外还有动态规划算法，时间复杂度一致
 */
string longestPalindrome(string s)
{
    // 判断以每个字符为中心的回文的最大长度 
    string result;
    for (int i=0; i<(int)s.length(); i++)
    {
        string r = get_palindromic(s, i);
        if (r.length() > result.length())
        {
            result = r;
        }
    }
    return result;
}

int main()
{
    cout << longestPalindrome("a") << endl;
    return 1;
}
