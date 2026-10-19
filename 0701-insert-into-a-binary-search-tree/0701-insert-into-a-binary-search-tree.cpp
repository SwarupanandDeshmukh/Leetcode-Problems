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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode *newNode = new TreeNode(val);

        if(root == NULL)
        {
            root = newNode;
            return root;
        }

        TreeNode* temp = root;

        while(temp != NULL)
        {
            if(val > temp->val)
            {
                if(temp->right == NULL)
                {
                    temp->right = newNode;
                    break;
                }
                temp = temp->right;
            }
            else
            {
                if(temp->left == NULL)
                {
                    temp->left = newNode;
                    break;
                }
                temp = temp->left;
            }
        }

        return root;
        
    }
};