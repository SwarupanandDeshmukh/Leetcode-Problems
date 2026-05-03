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

    void helper(TreeNode *root, unordered_map<int,int> &m)
    {
        if(root == NULL)
            return;
        
        m[root->val]++;
        helper(root->left,m);
        helper(root->right,m);
    }
    vector<int> findMode(TreeNode* root) {
        
        unordered_map<int, int> m;
        helper(root, m);

        auto max_it = max_element(m.begin(), m.end(),
        [](const auto &a, const auto &b)
        {
            return a.second < b.second;
        });

        vector<int> res;
        int mvalue = max_it->second;

        for(const auto& [key,value] : m)
        {
            if(value == mvalue)
            {
                res.push_back(key);
            }
        }

        return res;
        

    }
};