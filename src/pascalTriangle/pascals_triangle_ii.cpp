#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        for (int i=0; i<=rowIndex; i++)
        {
            for (int j=(i-1); j>=0; j--)
            {
                result[j] = result[j - 1] + result[j];
            }            
            result.push_back(1);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> result = solution.getRow(1);
    for (int i=0; i<result.size(); i++)
    {
        cout << result[i] << "\t";        
    }
    cout << endl;
    return 0;
}