#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 二叉树的链式存储结构
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**                                                                                                                                                                             
 * 先序遍历二叉树的递归形式
  */
void preorder_traverse_recursion(TreeNode *root)
{
    if (!root)
    {   
        return;
    }   

    printf("%d\t", root->val);

    preorder_traverse_recursion(root->left);

    preorder_traverse_recursion(root->right);
}

class Solution {
public:
    typedef vector<int>::iterator Iter;
    /**
      * iterator的end()区间为最后一个元素的下一个位置，因此这里将位置-1后前移一位
      */
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0)
        {
            return NULL;
        }
        return buildTree(preorder.begin(), preorder.end() - 1, inorder.begin(), inorder.end() - 1);
    }

    TreeNode *buildTree(Iter pre_begin, 
                        Iter pre_end,
                        Iter in_begin,
                        Iter in_end)
    {
        int root_value = *pre_begin;
        Iter iter = find(in_begin, in_end, root_value);
        TreeNode *root = new TreeNode(root_value);
        if (iter != in_begin)
        {
            root->left = buildTree(pre_begin + 1, pre_begin + (iter - in_begin), in_begin, iter - 1);
        }
        if (iter != in_end)
        {
            root->right = buildTree(pre_begin + (iter - in_begin) + 1, pre_end, iter + 1, in_end);
        }
        return root;
    }
};

int main()
{
    int pre[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int in[] = {4, 7, 2, 1, 5, 3, 8, 6};
    vector<int> preorder(pre, pre + sizeof(pre) / sizeof(int));
    vector<int> inorder(in, in + sizeof(in) / sizeof(int));
    Solution solution;
    preorder_traverse_recursion(solution.buildTree(preorder, inorder));
    return 1;
}
