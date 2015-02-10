#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        vector<int> array;
        for (int i=0; i<numRows; i++)
        {
            array.clear();
            for (int j=0; j<=i; j++)
            {
                if (j == 0 || j == i)
                {
                    array.push_back(1);
                }
                else
                {
                    array.push_back(result[i - 1][j - 1] + result[i - 1][j]);
                }
            }
            result.push_back(array);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int> > result = solution.generate(10);
    for (int i=0; i<result.size(); i++)
    {
        for (int j=0; j<result[i].size(); j++)
        {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}