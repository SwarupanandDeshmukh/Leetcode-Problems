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

    int searching(vector<int> &inorder, vector<int> preorder, int v, int l, int r)
    {
        for(int i = l; i<=r; i++)
        {
            if(inorder[i] == v)
                return i;
        }
        return -1;
    }

    TreeNode* helper(vector<int> &inorder, vector<int> &preorder, int &pidx, int l, int r)
    {
        if(l > r)
            return NULL;

        TreeNode *root = new TreeNode(preorder[pidx]);
        pidx++;

        int i = searching(inorder, preorder, root->val, l,r);
        root->left = helper(inorder, preorder, pidx, l, i-1);
        root->right = helper(inorder, preorder, pidx, i+1, r);

        return root;

    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());

        int pidx = 0;
       return helper(inorder, preorder, pidx, 0, inorder.size()-1);
    }
};