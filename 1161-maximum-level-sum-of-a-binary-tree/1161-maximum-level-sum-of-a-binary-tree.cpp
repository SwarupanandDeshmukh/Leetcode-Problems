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
    int maxLevelSum(TreeNode* root) {

        vector<int> res;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);

        int sum = 0;
        while(!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if(temp == NULL)
            {
                res.push_back(sum);
                sum = -0;
                if(q.empty())
                    break;
                q.push(NULL);
            }
            else
            {
                sum = sum + temp->val;

                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }

        int maxi = INT_MIN;
        int n = res.size();
        int sidx = 0;
        for(int i = 0; i<n; i++)
        {
            if(res[i] > maxi)
            {
                maxi = res[i];
                sidx = i;
            }
        }

        return sidx + 1;
    }
};