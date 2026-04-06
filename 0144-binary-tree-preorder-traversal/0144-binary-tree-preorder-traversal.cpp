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
    
    vector<int> preorderTraversal(TreeNode* root) {

        stack<TreeNode*> s;
        vector<int> res;
        TreeNode *temp = root;
        s.push(temp);
        while(!s.empty())
        {
            temp = s.top();
            s.pop();

            if(temp == NULL)
                continue;
            res.push_back(temp->val);
            s.push(temp->right);
            s.push(temp->left);
        }

        return res;    
    
    }
};