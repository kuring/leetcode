#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 该题较为简单，递归访问树，如果为叶子节点则判断值是否为sum即可
 *
 * 如果将该题变换为求树中任意路径的和为sum，则解题思路为：
 * 递归访问树中的节点（中序遍历形式），每访问一个节点就检测该节点是否满足和为sum的路径的末端，这就要求访问节点时要将访问节点的所有父节点序列全部传递过去
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL)
        {
            return false;
        }
        // leaf node
        if (root->left == NULL && root->right == NULL)  
        {
            if (root->val == sum)
            {
                return true;
            }
            return false;
        }

        // not leaf node
        bool left_result = false, right_result = false;
        if (root->left != NULL)
        {
            left_result = hasPathSum(root->left, sum - root->val);
        }
        if (root->right != NULL)
        {
            right_result = hasPathSum(root->right, sum - root->val);
        }
        if (left_result || right_result)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right = new TreeNode(8);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    root->right->left = new TreeNode(13);

    Solution solution;
    printf("%s\n", solution.hasPathSum(root, 20) ? "ture" : "false");
}
