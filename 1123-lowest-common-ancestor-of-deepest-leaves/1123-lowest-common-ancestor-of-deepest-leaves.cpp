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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) {
        
        if(root == NULL)
            return NULL;

        if(root == a || root == b)
            return root;
        
        TreeNode* leftLCA = lowestCommonAncestor(root->left, a,b);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, a,b);
            
        if(leftLCA && rightLCA)
            return root;
        if(leftLCA != NULL)
            return leftLCA;
        else
            return rightLCA;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
            vector<TreeNode*> curr;
            vector<TreeNode*> deepest;
            queue<TreeNode*> q;
            q.push(root);
            q.push(NULL);
            while(!q.empty())
            {
                TreeNode *temp = q.front();
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
                    if(!temp->left && !temp->right)
                        curr.push_back(temp);
                    if(temp->left)
                        q.push(temp->left);
                    if(temp->right)
                        q.push(temp->right);
                }
            }

        int n = deepest.size();
        TreeNode *a = deepest[0];
        TreeNode *b = deepest[n-1];
        
        if(n > 1)
        {
            TreeNode* lca = lowestCommonAncestor(root, a,b);
            return lca;
        }
    
        return a;
    }
};