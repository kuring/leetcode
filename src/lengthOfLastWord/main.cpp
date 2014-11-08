#include <stdio.h>
#include <stddef.h>

class Solution {
public:
    int lengthOfLastWord(const char *s) {
    	if (s == NULL || s[0] == '\0')
		{
			return 0;
		}

		int begin_site = 0;
		int end_site = 0;
		bool flag = false;
		for (int i = 0; s[i] != NULL; i++)
		{
			if (s[i] == ' ')
			{				
				flag = true;
			}
			else 
			{
				if (flag)
				{
					begin_site = i;
					flag = false;
				}
				end_site = i + 1;
			}
		}
		return end_site - begin_site;
    }
};

int main()
{
	Solution solution;
	int result = solution.lengthOfLastWord("   ");
	printf("%d\n", result);
	return 1;
}
