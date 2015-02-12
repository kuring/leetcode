#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution {
public:
    // 采用深度优先搜索的递归形式，需要注意边界条件的判断
    bool exist(vector<vector<char> > &board, string word) {
        vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i=0; i<board.size(); i++)
        {
            for (int j=0; j<board[i].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    if (exist(board, word, 0, i, j, visited))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char> > &board, string word, int site, int row, int col, vector<vector<bool> > &visited)
    {
        if (site == word.size())
        {
            return true;
        }
        if (row < 0 || row >= board.size())
        {
            return false;
        }
        if (col < 0 || col >= board[row].size())
        {
            return false;
        }
        
        if (board[row][col] != word[site])
        {
            return false;
        }
        
        if (visited[row][col])
        {
            return false;
        }
        visited[row][col] = true;
        
        if (exist(board, word, site + 1, row - 1, col, visited) ||
            exist(board, word, site + 1, row + 1, col, visited) ||
            exist(board, word, site + 1, row, col - 1, visited) ||
            exist(board, word, site + 1, row, col + 1, visited))
        {
            return true;
        }       
        visited[row][col] = false;
        return false;
    }
};

int main()
{
    vector<vector<char> > board;
    char b[3][5] ={"aaaa", "aaaa", "aaaa"};
    for (int i=0; i<sizeof(b) / sizeof(b[0]); i++)
    {
        vector<char> tmp;
        for (int j=0; j<strlen(b[i]); j++)
        {
            tmp.push_back(b[i][j]);
        }
        board.push_back(tmp);
    }
    
    Solution solution;
    cout << solution.exist(board, "aaaaaaaaaaaaa") << endl;
    return 0;
}