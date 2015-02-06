#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q)
		{
			return true;
		}
		if ((!p && q) || (p && !q) || p->val != q->val)
		{
			return false;
		}
		if (!isSameTree(p->left, q->left))
		{
			return false;
		}
		if (!isSameTree(p->right, q->right))
		{
			return false;
		}
		return true;
    }
};

int main()
{
	TreeNode *left = new TreeNode(0);
	TreeNode *right = new TreeNode(0);
	Solution solution;
	cout << solution.isSameTree(left, right) << endl;
	return 0;
}