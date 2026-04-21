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

    void helper(TreeNode *root, vector<string> &res, string &s)
    {
        if(root == NULL)
            return;
        
        s += to_string(root->val);

        if(!root->left && !root->right)
        {
            res.push_back(s);
        }
        else
        {
            helper(root->left,res, s);
            helper(root->right, res, s);
        }
        s.pop_back();
    }

    int sumNumbers(TreeNode* root) {
        vector<string> res;

        string s = "";

        helper(root, res, s);

        int sum = 0;
        for(string i : res)
        {
            sum = sum + stoi(i); 
        }

        return sum;

    }
};