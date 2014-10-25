// 难点在于对于超出最大整数和最小整数范围边界点的处理
// 经对比发现，陈浩对于边界点的处理方式更为简便
#include <stdio.h>
#include <limits.h>

class Solution
{
public:
	int atoi(const char *str)
	{
		int result = 0;
		int i = 0;
		int sign_bit = 1;	// the default sign bit is plus
		
		// discards the first many whitespace characters 
		for (; str[i] != '\0' && (str[i] == ' ' || str[i] == '0'); i++);

		// the first not space character
		if (str[i] == '-')
		{
			sign_bit = -1;
			i++;
		}
		else if (str[i] == '+')
		{
			sign_bit = 1;
			i++;
		}

		// begin convert
		for (; str[i] != '\0'; i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				if (result == 0 && str[i] == 0)
				{
					// the first number is 0
					continue;
				}
				if ((result > INT_MAX / 10 || 
					 (result == INT_MAX / 10 && (str[i] - '0') > (INT_MAX % 10)))
					)
				{
					// out of the range
					return sign_bit == -1 ? INT_MIN : INT_MAX;
				}
				else
				{
					result = result * 10 + str[i] - '0';
				}
			}
			else
			{
				// invalid number
				break;
			}
		}

		return result * sign_bit;
	}
};

int main()
{
	Solution solution;
	printf("%s  %d\n", "2147483648", solution.atoi("2147483648"));
	printf("%s  %d\n", "-2147483647", solution.atoi("-2147483647"));
	printf("%s  %d\n", "-2147483648", solution.atoi("-2147483648"));
	printf("%s  %d\n", "123", solution.atoi("123"));
	printf("%s  %d\n", "  -0012a42", solution.atoi("  -0012a42"));
	printf("%s  %d\n", "-123", solution.atoi("-123"));
	printf("%s  %d\n", "0123", solution.atoi("0123"));
	printf("%s  %d\n", "123a", solution.atoi("123a"));
}
