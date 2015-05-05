#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int begin = 0;
    int end = (int)matrix.size() - 1;

    //  首先利用二分查找法找到对应的行，这里的逻辑跟普通的二分查找有些区别，需要注意
    int row = 0;
    while (begin <= end)
    {
        if (begin == end)
        {
            row = begin;
            break;
        }
        if (end - 1 == begin)
        {
            if (target < matrix[end][0] && target >= matrix[begin][0])
            {
                row = begin;
                break;
            }
            else if (target >= matrix[end][0])
            {
                row = end;
                break;
            }
            return false;
        }
        int middle = (end + begin) / 2;
        if (matrix[middle][0] < target)
        {
            begin = middle;
        }
        else if (matrix[middle][0] > target)
        {
            end = middle;
        }
        else
        {
            return true; // 找到结果
        }
    cout << begin << "\t" << end << endl;
    }

    cout << "row = " << row << endl;

    // 利用二分查找法从行中查找
    begin = 0, end = matrix[row].size() - 1;
    while (begin <= end)
    {
        int middle = (end + begin) / 2;
        if (matrix[row][middle] < target)
        {
            begin = middle + 1;
        }
        else if (matrix[row][middle] > target)
        {
            end = middle - 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<int> > result = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    cout << searchMatrix(result, 80) << endl;
    return 1;
}
