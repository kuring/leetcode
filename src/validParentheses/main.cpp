// 我这里使用了stack来解决该问题，实际上string中已经包含了stack<char>结构的用法，只是我没用过不知道而已
#include <stdio.h>
#include <string>
#include <stack>
#include <queue>


using namespace std;

class Solution
{
public:
	bool isValid(string s)
	{
		stack<char> suffix_stack;
		for (int i=0; i<s.length(); i++)
		{
			if (s[i] == '(' ||
				s[i] == '[' ||
				s[i] == '{')
			{
				suffix_stack.push(s[i]);
			}
			else if (s[i] == ')' || 
					 s[i] == ']' || 
					 s[i] == '}')
			{
				if (suffix_stack.size() == 0)
				{
					return false;
				}
				if (is_match(suffix_stack.top(), s[i]))
				{
					suffix_stack.pop();
				}
				else
				{
					return false;
				}
			}
		}

		if (suffix_stack.size() > 0)
		{
			return false;
		}
		return true;
	}

private:
	bool is_match(char suffix, char postfix)
	{
		switch (suffix)
		{
			case '(':
				if (postfix == ')')
				{
					return true;
				}
				return false;
			case '[':
				if (postfix == ']')
				{
					return true;
				}
				return false;
			case '{':
				if (postfix == '}')
				{
					return true;
				}
				return false;
		}
		return false;
	}
};


int main()
{
	Solution solution;
	printf("%s %s\n", "()[]{}", solution.isValid("()[]{}") ? "true" : "false");
	printf("%s %s\n", "()", solution.isValid("()") ? "true" : "false");
	printf("%s %s\n", "([)]", solution.isValid("([)]") ? "true" : "false");
	printf("%s %s\n", "(]", solution.isValid("(]") ? "true" : "false");
}
