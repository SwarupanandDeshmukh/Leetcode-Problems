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

    int heightTree(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        
        int lht = heightTree(root->left);
        int rht = heightTree(root->right);

        return max(lht, rht) + 1;
    }

    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL)
            return 0;   
        
        if(!root->left && !root->right)
            return root->val;
        
        int height = heightTree(root);
        queue<TreeNode *> q;
        int cnt = 0;
        q.push(root);
        q.push(NULL);

        while(!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            if(temp == NULL)
            {
                cnt++;
                if(q.empty() || cnt == height - 1)
                    break;
                q.push(NULL);
            }
            else
            {
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
        }

        int sum = 0;
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();

            if(temp != NULL)
            {
                sum += temp->val;
            }
            else
                break;
        }

        return sum;
    }
};