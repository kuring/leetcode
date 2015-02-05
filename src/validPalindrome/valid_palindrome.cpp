#include <stdio.h>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

/**
 * 本题需要注意各种异常情况的处理
 * 题目中判断一个字符是否为字母或数字需要使用isalnum函数
 */
class Solution {
public:
    bool isPalindrome(string s) {
        if (s == "")
        {
            return true;
        }
        string::iterator head = s.begin();
        string::reverse_iterator tail = s.rbegin();
        for (; head != s.end() || tail != s.rend();)
        {
            while (head != s.end() && !isalnum(*head))
            {
                head++;
            }
            while (tail != s.rend() && !isalnum(*tail))
            {
                tail++;
            }
            if (head == s.end() && tail == s.rend())
            {
                return true;
            }
            if (tolower(*head) != tolower(*tail))
            {
                return false;
            }
            if (head != s.end())
            {
                head++;
            }
            if (tail != s.rend())
            {
                tail++;
            }            
        }
        if (head != s.end() || tail != s.rend())
        {
            return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    printf("%s\n", solution.isPalindrome("1a2") ? "true" : "false");
}