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


    bool findTarget(TreeNode* root, int k) {
        
        vector<int> res;
        helper(root, res);

        unordered_map<int,int> m;
        int n = res.size();

        for(int i =0; i<n; i++)
        {
            int diff = k - res[i];
            if(m.contains(diff))
            {
                return true;
            }
            else
            {
                m.insert({res[i],diff});
            }
        }
        
        return false;
    }
};