#include <stdio.h>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	// 以i为根节点的数，左子树由[1,i-1]个节点构成，右子树由[i+1,n]构成
	vector<TreeNode *> generateTrees(int n) {
		vector<TreeNode *> sub_tree = generateTrees(1, n);
		return sub_tree;
	}
	
	vector<TreeNode *> generateTrees(int low, int high) {
		vector<TreeNode *> result;
		if (low > high)
		{
			result.push_back(NULL);
			return result;
		}
		else if (low == high)
		{
			TreeNode *node = new TreeNode(low);
			result.push_back(node);
			return result;
		}
		
		for (int i=low; i<=high; i++)
		{
			vector<TreeNode *> left = generateTrees(low, i - 1);
			vector<TreeNode *> right = generateTrees(i + 1, high);
			for (int j=0; j<left.size(); j++)
			{
				for (int k=0; k<right.size(); k++)
				{
					TreeNode *root = new TreeNode(i);
					root->left = left[j];
					root->right = right[k];
					result.push_back(root);
				}
			}
		}
		return result;
	}
};

void printTree(TreeNode *root){
    if (root == NULL){
        printf("# ");
        return;
    }
    printf("%d ", root->val );

    printTree(root->left);
    printTree(root->right);
}

int main()
{
	Solution solution;
	vector<TreeNode *> results = solution.generateTrees(1);
	for (vector<TreeNode *>::iterator iter = results.begin(); iter != results.end(); iter++)
	{
		printTree(*iter);
		printf("\n\n");
	}
	return 1;
}
