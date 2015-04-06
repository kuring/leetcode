#include <string>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<string> generateParenthesis(string s)
{
    set<string> result;
    for (size_t i = 0; i < s.length(); i++)
    {
        string tmp = s;
        tmp.insert(i, "(");
        int begin_size = 0;
        int end_size = 0;
        for (size_t j = i + 1; j <= tmp.length(); j++)
        {
            string tmp2 = tmp;
            if (begin_size == end_size)
            {
                tmp2.insert(j, ")");
                result.insert(tmp2);
            }
            if (j < tmp.length())
            {
                if (tmp[j] == '(')
                {
                    begin_size++;
                }
                else if (tmp[j] == ')')
                {
                    end_size++;
                }
            }
        }
    }
    return result;
}

/**
 * 我这里使用了从n=1时开始逐级构造结果集的方式，比较麻烦的地方在于需要去重处理，我这里去重使用了set
 * 另外还有的思路为利用递归的方式，当左括号数小于n时可以放置左括号，当右括号数小于左括号时可以放置右括号，该思路由于是递归实现，代码比较少
 */
vector<string> generateParenthesis(int n)
{
    vector<string> result;
    if (n <= 0)
    {
        return result;
    }

    int i = 2;
    set<string> result_set;
    result_set.insert("()");
    while (i <= n)
    {
        set<string> old_result_set = result_set;
        result_set.clear();
        for (set<string>::iterator iter = old_result_set.begin(); iter != old_result_set.end(); iter++)
        { 
            set<string> r = generateParenthesis(*iter); 
            for (set<string>::iterator iter2 = r.begin(); iter2 != r.end(); iter2++)
            {
                result_set.insert(*iter2);
            }
        }
        i++;
    }

    for (set<string>::iterator iter = result_set.begin(); iter != result_set.end(); iter++)
    {
        result.push_back(*iter);
    }
    return result;
}

int main()
{
    vector<string> result = generateParenthesis(3);
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 1;
}
