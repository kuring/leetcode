#include <stdio.h>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
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
	root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(1);
	root->right->left = new TreeNode(13);

	Solution solution;
	vector<vector<int> > results = solution.hasPathSum(root, 20);
	
	for (int i=0; i<results.size(); i++)
	{
		for (int j=0; j<results[i].size(); j++)
		{
			printf("%d\t", results[i][j]);
		}
		printf("\n");
	}
}
