#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generateMatrix(int n)
{
    vector<vector<int> > result(n, vector<int>(n));
    if (n <= 0)
    {
        return result;
    }
    
    int direct = 1;
    int begin_row = 0, end_row = n - 1;
    int begin_column = 0, end_column = n - 1;
    int number = 1;
    size_t i = 0, j = 0;
    while (number <= n * n)
    {
        result[i][j] = number++;
        switch (direct)
        {
            case 1:
                if (j < end_column)
                {
                    j++;
                }
                else
                {
                    i++;
                    direct++;
                    begin_row++;
                }
                break;
            case 2:
                if (i < end_row)
                {
                    i++;
                }
                else
                {
                    j--;
                    direct++;
                    end_column--;
                }
                break;
            case 3:
                if (j > begin_column)
                {
                    j--;
                }
                else
                {
                    i--;
                    direct++;
                    end_row--;
                }
                break;
            case 4:
                if (i > begin_row)
                {
                    i--;
                }
                else
                {
                    j++;
                    begin_column++;
                    direct = 1;
                }
                break;
        }
    }
    return result;
}

int main()
{
    vector<vector<int> > result = generateMatrix(5);
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
