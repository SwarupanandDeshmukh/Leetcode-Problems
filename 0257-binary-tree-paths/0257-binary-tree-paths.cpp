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

    void helper(TreeNode* root, string s, vector<string> &res)
    {
        if(root == NULL)
            return;
        
        s += to_string(root->val);
        s += "->";

        if(root->left == NULL && root->right == NULL)
        {
            s.pop_back();
            s.pop_back();
            res.push_back(s);
        }
        else
        {
            helper(root->left, s, res);
            helper(root->right, s, res);
        }
        s.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        
       vector<string> res;
       string s = "";
       if(root == NULL)
        return {};

        helper(root,s, res);

        return res;


    }
};