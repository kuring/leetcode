#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		stack<TreeNode *> node_stack;
		if (root != NULL)
		{
			node_stack.push(root);
		}
		
		while (!node_stack.empty())
		{
			TreeNode *node = node_stack.top();
			node_stack.pop();
			result.push_back(node->val);
			if (node->right != NULL)
			{
				node_stack.push(node->right);
			}
			if (node->left != NULL)
			{
				node_stack.push(node->left);
			}			
		}
		
		return result;
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
	vector<int> results = solution.preorderTraversal(root);

	for (int i=0; i<results.size(); i++)
	{
		printf("%d\t", results[i]);
	}
	printf("\n");
}
