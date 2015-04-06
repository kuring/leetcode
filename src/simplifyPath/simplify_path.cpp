#include <iostream>
#include <string>
#include <stack>

using namespace std;

/**
 * 利用栈来实现，主要是需要注意对边界情况的处理
 */
string simplifyPath(string path)
{
    stack<string> s;
    size_t p1 = 0, p2 = 0;
    bool end = false;
    while (p1 < path.length() && !end)
    {
        p2 = path.find('/', p1 + 1);
        if (p2 == string::npos)
        {
            p2 = path.length() - 1;
            end = true;
        }
        
        // the path might contain multiple slashes '/' together, such as "/home//foo/"
        if (!end && p1 + 1 == p2)
        {
            p1 = p2;
            continue;
        }
        string name;
        if (end)
        {
            name = path.substr(p1 + 1, p2 - p1);
        }
        else
        {
            name = path.substr(p1 + 1, p2 - p1 - 1);
        }
        if (name == ".." && s.size() > 0)
        {
            s.pop();
        }
        else if (name.length() >= 1 && name != "." && name != "..")
        {
            s.push(name);
        }
        p1 = p2;
    }

    // 拼接栈中的路径 
    string result;
    while (s.size() > 0)
    {
        result.insert(0, s.top());
        s.pop();
        result.insert(0, "/");
    }
    if (result == "")
    {
        result = "/";
    }
    return result;
}

int main()
{
    cout << simplifyPath("/e") << endl;
}
