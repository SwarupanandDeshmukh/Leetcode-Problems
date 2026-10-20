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

    TreeNode* lca(TreeNode* root, TreeNode* a, TreeNode* b)
    {
        if(root == NULL)
            return NULL;
        
        if(root == a || root == b)
            return root;
        
        TreeNode* left = lca(root->left, a, b);
        TreeNode* right = lca(root->right, a, b);

        if(left == NULL && right == NULL)
            return NULL;
        else if(left == NULL && right != NULL)
            return right;
        else if(left != NULL && right == NULL)
            return left;
        else
            return root;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        vector<TreeNode*> curr;
        vector<TreeNode*> deepest;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();

            if(temp == NULL)
            {

                if(!curr.empty())
                    deepest = curr;
                curr.clear();
                if(q.empty())
                    break;
                q.push(NULL);
            }   
            else
            {
                curr.push_back(temp);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }

        int n = deepest.size();
        TreeNode* a = deepest[0];
        TreeNode *b = deepest[n-1];

        if(n > 1)
        {
            return lca(root, a, b);
        }

        return a;


    }
};