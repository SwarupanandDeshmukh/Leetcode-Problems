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

    int searching(vector<int>& inorder, vector<int>& postorder, int v, int l, int r)
    {
        for(int i = l; i<=r; i++)
        {
            if(inorder[i] == v)
                return i;
        }
        return -1;
    }

TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int &pidx, int left, int right)
{
    if(left > right)
        return NULL;
    
    TreeNode *root = new TreeNode(postorder[pidx]);
    pidx++;

    int i = searching(inorder, postorder, root->val, left, right);

    root->right = helper(inorder, postorder, pidx, i+1, right);
    root->left = helper(inorder, postorder, pidx, left, i-1);

    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int pidx = 0;
        reverse(postorder.begin(), postorder.end());

        return helper(inorder, postorder, pidx, 0, inorder.size() - 1);

    }
};