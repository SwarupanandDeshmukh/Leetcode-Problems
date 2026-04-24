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

    struct Node
    {
        TreeNode *curr;
        TreeNode *parent;
        TreeNode *grandparent;
    };
    int sumEvenGrandparent(TreeNode* root) {

        queue<Node> q;

        q.push({root, NULL, NULL});

        int sum = 0;
        while(!q.empty())
        {
            TreeNode *curr = q.front().curr;
            TreeNode *parent = q.front().parent;
            TreeNode *gp = q.front(). grandparent;
            q.pop();

            if(gp != NULL && gp->val % 2 == 0)
                sum += curr->val;
            
            if(curr->left)
                q.push({curr->left, curr, parent});
            
            if(curr->right)
                q.push({curr->right, curr, parent});
            
        }

        return sum;
    }
};