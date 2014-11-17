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
        if ((p && !q) || (!p && q)) {
            return false;
        }

        if (!p && !q) {
            return true;
        }

        bool nodeSame = p == q || p->val == q->val;        
        if (nodeSame) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);   
        } else {
            return false;
        }
    }
};

int main() {
	Solution sln;
	
    TreeNode *p, *q;
    p = new TreeNode(1);
    q = new TreeNode(1);
    q->left = new TreeNode(2);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    q->right = new TreeNode(4);

    cout << sln.isSameTree(p, q) << endl;
	return 0;
}