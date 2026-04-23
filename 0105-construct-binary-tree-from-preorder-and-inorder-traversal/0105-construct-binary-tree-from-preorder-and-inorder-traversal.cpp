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

    int searching(vector<int>& preorder, vector<int>& inorder, int v, int l, int r)
    {
        for(int i = l; i<= r; i++)
        {
            if(inorder[i] == v)
                return i;
        }

        return -1;
    }
TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int &pidx, int left, int right)
    {
        if(left > right)
            return NULL;
        
        TreeNode *root = new TreeNode(preorder[pidx]);
        pidx++;

        int i = searching(preorder, inorder, root->val, left, right);

        root->left = helper(preorder, inorder, pidx, left, i-1);
        root->right = helper(preorder, inorder, pidx, i+1, right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
       int pidx = 0;
       return helper(preorder, inorder, pidx, 0, inorder.size() - 1);
        
        
    }
};