#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
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

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (root == NULL)
        {
            return true;
        }
        int left = getMaxDepth(root->left);
        int right = getMaxDepth(root->right);
        if (abs(left - right) > 1)
        {
            return false;
        }
        return true;
    }

    int getMaxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left = getMaxDepth(root->left);
        int right = getMaxDepth(root->right);
        return max(left, right) + 1;
    }
};

int main()
{
//    int arr[] = {1, '#', 2, '#', 3};
    int arr[] = {1,2,2,3,'#','#',3,4,'#','#',4};
    TreeNode *root = create_binary_tree(arr, sizeof(arr) / sizeof(int));
    Solution solution;
    cout << solution.isBalanced(root) << endl;
}
