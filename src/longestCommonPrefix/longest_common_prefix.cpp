#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

/**
 * 逻辑题 
 */
string longestCommonPrefix(vector<string> &strs) {
    string result;
    if (strs.size() == 0)
    {
        return result;
    }
    if (strs.size() == 1)
    {
        return strs[0];
    }
    int i = 0;
    while (1)
    {
        int j = 0;
        char k = strs[j][i];
        j++;
        for (; j < (int)strs.size(); j++)
        {
            if (i >= (int)strs[j].length() || strs[j][i] != k)
            {
                return result;
            }
        }
        result += k;
        i++;
    }
    return result;
}

int main()
{
    vector<string> strs;
    strs.push_back("c");
    strs.push_back("c");
    cout << longestCommonPrefix(strs) << endl;
    return 1;
}
