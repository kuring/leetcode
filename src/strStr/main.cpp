// 对于KMP算法不打算深入研究，大体知道原理，使用时再做研究
#include <stdio.h>

class Solution {
public:
	// 效率破解方法，效率不是很高，算法复杂度为m*n，提交后，测试结果显示Time Limit Exceeded错误
    int strStr(char *haystack, char *needle) {
		if (haystack == NULL || needle == NULL)
		{
			return -1;
		}
		if (haystack[0] == '\0' || needle[0] == '\0')
		{
			return 0;
		}
		for (int i=0; haystack[i] != NULL; i++)
		{
			if (haystack[i] == needle[0])
			{
				int j = 0;
				bool flag = true;
				for (; needle[j] != NULL; j++)
				{
					if (haystack[i + j] == '\0')
					{
						flag = false;
						break;
					}
					if (needle[j] != haystack[i + j])
					{
						break;
					}
				}
				if (needle[j] == NULL && flag)
				{
					return i;
				}
			}
		}
		return -1;
    }
};

int main()
{
	char *bb = "ab";
	char *aa = "aab";
	Solution solution;
	int site = solution.strStr(aa, bb);
	printf("the site is %d\n", site);
}
