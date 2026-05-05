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

    void helper(TreeNode *root, vector<int> &res)
    {
        if(root == NULL)
            return;
        
        helper(root->left, res);
        res.push_back(root->val);
        helper(root->right, res);

    }

    bool isValidBST(TreeNode* root) {
        
        vector<int> res;
        helper(root, res);

        int n = res.size();
        int i = 0;
        int j = i+1;
        bool f = true;
        while(j<n)
        {
            if(res[i] >= res[j])
                f = false;
            i++;
            j++;
        }

        return f;
    }
};