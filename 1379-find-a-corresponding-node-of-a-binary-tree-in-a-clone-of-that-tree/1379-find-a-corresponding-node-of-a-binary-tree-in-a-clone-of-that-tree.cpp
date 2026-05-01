/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    struct Node
    {
        TreeNode *a;
        TreeNode *b;
    };

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        queue<Node> q;
        q.push({original, cloned});

        while(!q.empty())
        {   
            TreeNode *org = q.front().a;
            TreeNode *c = q.front().b;
            q.pop();

            if(org == target)
                return c;
            
            if(org->left)
                q.push({org->left, c->left});
            
            if(org->right)
                q.push({org->right, c->right});
        }

        return NULL;
    }
};