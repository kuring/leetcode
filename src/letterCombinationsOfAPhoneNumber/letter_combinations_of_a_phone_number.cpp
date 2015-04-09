#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<string> letterCombinations(string letters, vector<string> &input)
{
    vector<string> result;
    if (input.size() == 0)
    {
        for (size_t j = 0; j < letters.length(); j++)
        {
            string tmp;
            tmp += letters[j];
            result.push_back(tmp);
        }
    }
    else
    {
        for (size_t i = 0; i < input.size(); i++)
        {
            for (size_t j = 0; j < letters.length(); j++)
            {
                result.push_back(input[i] + letters[j]);
            }
        }
    }
    return result;
}

/**
 * 时间复杂度为O(3^n)，该问题往往用递归解决起来比较简单
 */
vector<string> letterCombinations(string digits)
{
    map<char, string> relation;
    relation['2'] = "abc";
    relation['3'] = "def";
    relation['4'] = "ghi";
    relation['5'] = "jkl";
    relation['6'] = "mno";
    relation['7'] = "pqrs";
    relation['8'] = "tuv";
    relation['9'] = "wxyz";

    vector<string> result;
    for (size_t i=0; i<digits.length(); i++)
    {
        result = letterCombinations(relation[digits[i]], result);
    }
    return result;
}

int main()
{
    vector<string> result = letterCombinations("23");
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 1;
}
