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
            return 0;
        
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
                if(q.empty())
                    break;
                q.push(NULL);
            }
            else
            {
                if(!temp->left && !temp->right)
                    break;
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }

        return cnt+1;
       
    }
};