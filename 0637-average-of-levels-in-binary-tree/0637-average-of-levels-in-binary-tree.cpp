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
    vector<double> averageOfLevels(TreeNode* root) {
        
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

        vector<double> result;
        int n = res.size();
        for(int i = 0; i<n; i++)
        {
            double sum = 0;
            for(int v : res[i])
            {
                sum = sum + v;
            }
            double avg = sum / res[i].size();
            result.push_back(avg);

        }

        return result;
    }
};