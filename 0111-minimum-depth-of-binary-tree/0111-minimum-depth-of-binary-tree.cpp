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
    int minDepth(TreeNode* root) {
        
        if(root == NULL)
            return {};
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        int lvl = 0;
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();

            if(temp == NULL)
            {
                lvl++;
                if(q.empty())
                    break;
                
                q.push(NULL);
            }

            else if(!temp->left && !temp->right)
            {
                break;
            }
            else
            {
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }

        }

        return lvl+1;
    }
};