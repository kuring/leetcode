#include <string>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 为了使用常量空间，使用了第一行和第一列来作为临时空间存储记录情况
 */
void setZeroes(vector<vector<int>>& matrix)
{
    if (matrix.size() == 0)
    {
        return ;
    }

    bool is_row_zero = false;
    bool is_column_zero = false;
    //  检测第一列是否存在0元素
    for (size_t i = 0; i < matrix.size(); i++)
    {
        if (matrix[i][0] == 0)
        {
            is_column_zero = true;
            break;
        }
    }

    // 检测第一行是否存在0
    for (size_t i = 0; i < matrix[0].size(); i++)
    {
        if (matrix[0][i] == 0)
        {
            is_row_zero = true;
            break;
        }
    }


    // 检测除去第一行第一列外的其他元素,如果存在0就将该行和该列的第一个元素更新为0
    for (size_t i = 1; i < matrix.size(); i++)
    {
        for (size_t j = 1; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // 检测第一列的值，根据情况更新对应的行
    for (size_t i = 1; i < matrix.size(); i++)
    {
        if (matrix[i][0] == 0)
        {
            for (size_t j = 1; j < matrix[i].size(); j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // 检测第一行的值，根据情况更新对应的列 
    for (size_t i = 1; i < matrix[0].size(); i++)
    {
        if (matrix[0][i] == 0)
        {
            for (size_t j = 1; j < matrix.size(); j++)
            {
                matrix[j][i] = 0;
            }
        }
    }
    
    if (is_column_zero)
    {
        for (size_t i = 0; i < matrix.size(); i++)
        {
            matrix[i][0] = 0;
        }
    }
    if (is_row_zero)
    {
        for (size_t i = 0; i < matrix[0].size(); i++)
        {
            matrix[0][i] = 0;
        }
    }
}

int main()
{
    vector<vector<int> > result = {{1,0,3,4},{5,6,0,8},{9,10,11,12},{13,14,15,16}};
    setZeroes(result);
    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }
    return 1;
}
