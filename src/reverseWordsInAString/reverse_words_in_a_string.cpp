#include <string>
#include <iostream>

using namespace std;

/**
 * 本题的思路为：
 * 1. 首先去除空格，去除开始和结束和字符串中重复出现的空格
 * 2. 反转整个字符串
 * 3. 反转字符串中的单个词
 * 其中，第一步和第二步的操作可以合并为一个函数中处理，本程序为了简化没有做此处理
 *
 * 如果本题没有空间复杂度为O(1)的限制，则思路较多
 */
class Solution {
    public:
        void reverseWords(string &s) {
            reduce_space(s);
            reverseWord(s, 0, s.length() - 1);

            // reverse a word
            int i = 0, j = 0;
            while (i < (int)s.length())
            {
                if (s[i] == ' ')
                {
                    reverseWord(s, j, i - 1);
                    j = i + 1;
                }
                i++;
            }
            if (i != j)
            {
                reverseWord(s, j, i - 1);
            }
        }

        void reduce_space(string &s)
        {
            int j = 0, i = 0;
            int length = s.length();
            while (s[i] == ' ')
            {
                i++;
            }
            for (; i<length; i++, j++)
            {
                while (i < length - 1  && s[i] == ' ' && s[i + 1] == ' ')
                {
                    i++;
                }
                s[j] = s[i];
            }
            s.erase(j, i - j);
            while (s[--j] == ' ')
            {
                s.erase(j);
            }
        }

        void reverseWord(string &s, int left, int right)
        {
            while (left < right)
            {
                char tmp = s[left];
                s[left] = s[right];
                s[right] = tmp;
                right--;
                left++;
            }
        }
};

int main()
{
//    string s = " the  sky is blue ";
    string s = "   a   b ";
    Solution solution;
    solution.reverseWords(s);
    cout << s << endl;
}
