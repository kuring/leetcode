#include <iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
		string result;
        while (n > 0)
		{
			result.insert(0, 1, ('A' + (n - 1) % 26));
			n = (n - 1) / 26;
		}
		return result;
    }
};

int main()
{
	Solution solution;
	cout << solution.convertToTitle(26) << endl;
	return 0;
}