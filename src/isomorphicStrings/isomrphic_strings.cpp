#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }
    map<char, char> forward;
    map<char, char> reverse;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (forward.find(s[i]) != forward.end())
        {
            if (forward[s[i]] != t[i])
            {
                return false;
            }
        }
        else
        {
            forward[s[i]] = t[i];
        }
        
        if (reverse.find(t[i]) != reverse.end())
        {
            if (reverse[t[i]] != s[i])
            {
                return false;
            }
        }
        else
        {
            reverse[t[i]] = s[i];
        }
    }

    return true;
}

int main()
{
    cout << isIsomorphic("foo", "bar") << endl;
    return 1;
}
