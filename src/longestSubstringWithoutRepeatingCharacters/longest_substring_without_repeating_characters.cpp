#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 一步步往前搜索匹配
    // 采用了哈希来解决查找字符是否在字符串中的问题
    // 需要特别注意边界条件的处理
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int begin = 0;
        int max = 0;
        for (int i=0; i<s.length(); i++)
        {
            if (m.find(s[i]) != m.end())
            {
                if (max < i - begin)
                {
                    max = i - begin;
                }
                for (int j=begin; j<m[s[i]]; j++)
                {
                    m.erase(s[j]);
                }
                begin = m[s[i]] + 1;
            }
            m[s[i]] = i;
        }
        return std::max(max, (int)(s.length() - begin));
    }
};

int main()
{
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abba");
    cout << endl;
    return 0;
}