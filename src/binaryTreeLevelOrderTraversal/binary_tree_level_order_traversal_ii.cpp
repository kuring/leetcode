#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *create_binary_tree(int arr[], int size)
{
    if (size <= 0)
    {
        return NULL;
    }

    TreeNode **node = new TreeNode*[size];
    for (int i=0; i<size; i++)
    {
        if (arr[i] == '#')
        {
            node[i] = NULL;
        }
        else
        {
            node[i] = new TreeNode(arr[i]);
        }
    }

    int pos = 1;
    for (int i=0; i<size && pos < size; i++)
    {
        if (node[i])
        {
            node[i]->left = node[pos++];
            if (pos < size)
            {
                node[i]->right = node[pos++];
            }
        }
    }

    return node[0];
}

/**
 * 本题比较好的解题思路就是按照正序求得结果后再将结果集反转
 */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        travel_tree(root, result, 0);
        reverse(result.begin(), result.end());
        return result;
    }

    void travel_tree(TreeNode *root, vector<vector<int> > &result, int level)
    {
        if (!root)
        {
            return ;
        }

        if (result.size() < level + 1)
        {
            vector<int> tmp;
            tmp.push_back(root->val);
            result.push_back(tmp);
        }
        else
        {
            result[level].push_back(root->val);
        }
        travel_tree(root->left, result, level + 1);
        travel_tree(root->right, result, level + 1);
    }

};

int main()
{
//    int arr[] = {1, '#', 2, '#', 3};
    int arr[] = {1,2,2,3,'#','#',3,4,'#','#',4};
    TreeNode *root = create_binary_tree(arr, sizeof(arr) / sizeof(int));
    Solution solution;
    vector<vector<int> > result = solution.levelOrder(root);
    for (int i=0; i<(int)result.size(); i++)
    {
        for (int j=0; j<(int)result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
