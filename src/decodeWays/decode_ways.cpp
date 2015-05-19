#include <string>
#include <iostream>
#include <map>
#include <string.h>
using namespace std;

int numDecodings(string &s, int site, map<int, int> &cache)
{
	cout << "deal : " << s << " site=" << site << endl;
	
	if (s.length() - site < 1)
	{
		// 没有元素
		return 0;
	}
	else if (s.length() - site == 1)
	{
		// 最后只剩下一个元素
		if (s[site] == '0')
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	
	if (s[site] == '0')
	{
		return 0;
	}
	
	if (cache.find(site) != cache.end())
	{
		return cache[site];
	}
	
	string sub = s.substr(site, 2);
	int two = 0;
	if ((sub[0] == '1') || (sub[0] == '2' && sub[1] <= '6'))
	{
		two = numDecodings(s, site + 2, cache) + 1;
	}
	int result = numDecodings(s, site + 1, cache) + two;
	cache[site] = result;
	return result;
}

// 不能使用深搜+备忘录，其中注释部分为深搜代码
// 当字符串中出现0时，需要废弃此路线，比如100，结果为0; 110,结果为1
// 采用动态规划方式，类似于爬台阶的思路
int numDecodings(string s)
{
	/*map<int, int> cache;
	return numDecodings(s, 0, cache);*/
	if (s.empty() || s[0] == '0')
	{
		return 0;
	}
	
	int *result = new int[s.length() - 1];
	memset(result, 0, (s.length() - 1) * sizeof(int));
	if (s[0] != '0')
	{
		result[0] = 1;
	}
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6')
		{
			if (s[i] == '0')
			{
				if (i - 2 > 0)
				{
					result[i] = result[i - 2];
				}
				else
				{
					result[i] = 1;
				}
			}
			else
			{
				if (i - 2 > 0)
				{
					result[i] = result[i - 2] + result[i - 1];
				}
				else 
				{
					result[i] = 1 + result[i - 1];
				}
			}
		}
		else
		{
			if (s[i] == '0')
			{
				result[i] = 0;
			}
			else
			{
				result[i] = result[i - 1];
			}
		}
	}
	return result[s.length() - 1];
}

int main()
{
	cout << numDecodings("10") << endl;
	return 1;
}