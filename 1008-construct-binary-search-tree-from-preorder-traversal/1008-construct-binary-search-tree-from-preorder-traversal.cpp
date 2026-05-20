/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode *helper(vector<int> &preorder, int &pidx, int bound)
    {
        if(pidx == preorder.size() || preorder[pidx] > bound)
            return NULL;

        TreeNode *root = new TreeNode(preorder[pidx]);
        pidx++;

        root->left = helper(preorder, pidx, root->val);
        root->right = helper(preorder, pidx, bound);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        int pidx = 0;
        int i = INT_MAX;
       return helper(preorder, pidx, i);
    }
};