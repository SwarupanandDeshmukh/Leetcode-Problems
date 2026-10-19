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

    TreeNode* invert(TreeNode* p)
    {  
        if(p == NULL)
            return NULL;
        
        swap(p->left, p->right);

        invert(p->left);
        invert(p->right);

        return p;
    }

    bool Same(TreeNode *temp, TreeNode *q)
    {
        if(temp == NULL && q == NULL)
            return true;
        
        if(temp != NULL && q == NULL)
            return false;
        
        if(temp == NULL && q != NULL)
            return false;
        
        if(temp->val != q->val)
            return false;
        
        return Same(temp->left, q->left) && Same(temp->right, q->right);

    }

    bool isSymmetric(TreeNode* root) {
        
        TreeNode *temp = invert(root->left);

        return Same(temp, root->right);

    }
};