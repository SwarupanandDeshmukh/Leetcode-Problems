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

    void helper(TreeNode* root, vector<int> inner, vector<vector<int>> &res)
    {
        if(root == NULL)
            return;
        
        inner.push_back(root->val);

        if(!root->left && !root->right)
        {
            res.push_back(inner);
        }
        else
        {
            helper(root->left, inner, res);
            helper(root->right, inner, res);
        }
        inner.pop_back();
    }

    bool hasPathSum(TreeNode* root, int targetSum) {

        if(root == NULL)
            return false;
        
        vector<vector<int>> res;
        vector<int> inner;
        helper(root, inner, res);

        int n = res.size();
        for(int i = 0; i<n; i++)
        {  
            int sum = 0;
            for(int v : res[i])
            {
                sum = sum + v;
            }

            if(sum == targetSum)
                return true;

        }

        return false;
    }
};