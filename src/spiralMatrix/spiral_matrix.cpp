#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix)
{
    vector<int> result;
    size_t row = matrix.size();
    if (row == 0)
    {
        return result;
    }
    size_t column = matrix[0].size();
    if (column == 0)
    {
        return result;
    }

    // direct表示当前遍历的方向，1 左->右; 2 上->下; 3 右->左; 4 下->上
    int direct = 1;
    int i = 0, j = 0;
    size_t begin_row = 0, end_row = row - 1;
    size_t begin_column = 0, end_column = column - 1;
    while (end_row >= begin_row &&
           end_column >= begin_column &&
           i >= 0 &&
           j >= 0)
    {
        result.push_back(matrix[i][j]);
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
    //vector<vector<int> > matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<vector<int> > matrix = {{3}, {6}};
    vector<int> result = spiralOrder(matrix);

    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 1;
}
