#include <string>
#include <iostream>
#include <vector>

using namespace std;


int main()
{
    vector<vector<int> > result;
    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 1;
}
