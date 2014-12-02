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
    int minDepth(TreeNode *root) {
        if (root == NULL)
		{
			return 0;
		}
		// leaf node
    	if (root->left == NULL && root->right == NULL)  
		{
			return 1;
		}
		
		int result;
		if (root->left != NULL && root->right != NULL)
		{
			result = std::min(minDepth(root->left), minDepth(root->right)) + 1;
		}
		else if (root->left == NULL && root->right != NULL)
		{
			result = minDepth(root->right) + 1;
		}
		else if (root->left != NULL && root->right == NULL)
		{
			result = minDepth(root->left) + 1;
		}
		return result;
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
	printf("%d\n", solution.minDepth(root));
}
