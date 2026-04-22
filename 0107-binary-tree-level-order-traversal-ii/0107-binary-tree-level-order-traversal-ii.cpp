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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if(root == NULL)
            return {};
        
        vector<vector<int>> res;
        vector<int> inner;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            if(temp == NULL)
            {
                res.push_back(inner);
                inner.clear();
                if(q.empty())
                    break;
                q.push(NULL);
            }
            else
            {
                inner.push_back(temp->val); 

                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }

        reverse(res.begin(), res.end());
        return res;

    }
};