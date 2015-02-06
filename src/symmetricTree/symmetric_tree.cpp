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
    bool isSymmetric(TreeNode *root) {
        return isMirrorTree(root, root);
    }
    
private:
    bool isMirrorTree(TreeNode *p, TreeNode *q) {
        if (!p && !q)
        {
            return true;
        }
        if ((!p && q) || (p && !q) || p->val != q->val)
        {
            return false;
        }
        if (!isMirrorTree(p->left, q->right))
        {
            return false;
        }
        if (!isMirrorTree(p->right, q->left))
        {
            return false;
        }
        return true;
    }
};

int main()
{
    TreeNode *root = new TreeNode(0);
    Solution solution;
    cout << solution.isSymmetric(root) << endl;
    return 0;
}