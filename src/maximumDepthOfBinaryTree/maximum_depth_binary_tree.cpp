#include <stdio.h>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == NULL)
		{
			return 0;
		}
		return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main()
{
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	/*root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);
	root->right->left = new TreeNode(13);*/

	Solution solution;
	printf("%d\n", solution.maxDepth(root));
}