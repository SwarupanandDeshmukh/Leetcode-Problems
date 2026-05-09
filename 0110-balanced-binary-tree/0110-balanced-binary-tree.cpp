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
  int height(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        
        int lht = height(root->left);
        int rht = height(root->right);
        
        return max(lht, rht) + 1;
    }

    bool isBalanced(TreeNode* root) {

        if(root == NULL)
            return true;
        
        int lht = height(root->left);
        int rht = height(root->right);

        if((rht - lht) > 1 || (lht - rht) > 1)
            return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
};