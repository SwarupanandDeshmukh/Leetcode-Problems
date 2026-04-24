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
    };

    int sumOfLeftLeaves(TreeNode* root) {
        
        if(!root->left && !root->right)
            return 0;
        
        queue<Node> q;

        q.push({root, NULL});

        int sum = 0;
        while(!q.empty())
        {
            TreeNode *curr = q.front().curr;
            TreeNode *parent = q.front(). parent;
            q.pop();

            if(!curr->left && !curr->right && parent->left == curr)
                sum = sum + curr->val;
            
            if(curr->left)
                q.push({curr->left, curr});
            
            if(curr->right)
                q.push({curr->right, curr});
            
        }

        return sum;

    }
};