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


    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL)
            return NULL;
        
        TreeNode* temp = root;
        TreeNode* delNode = NULL;
        TreeNode* delParent = NULL;
        while(temp != NULL)
        {
            if(key == temp->val)
            {
                delNode = temp;
                break;
            }
            else if(key > temp->val)
            {
                delParent = temp;
                temp = temp->right;
            }
            else
            {
                delParent = temp;
                temp = temp->left;
            }
        }

        if(delNode == NULL)
            return root;
        
        if(delNode->left == NULL && delNode->right == NULL)
        {
            if(delParent == NULL)
            {
                delete delNode;
                return NULL;
            }

            if(delParent->left == delNode)
                delParent->left = NULL;
            else
                delParent->right = NULL;

            delete delNode;
            return root;
        }

        else if(delNode->left == NULL || delNode->right == NULL)
        {
           TreeNode *child;

           if(delNode->left == NULL)
                child = delNode->right;
    
           if(delNode->right == NULL)
            child = delNode->left;

            if(delParent == NULL)
            {
                delete delNode;
                return child;
            }

            if(delParent->left == delNode)
                delParent->left = child;
            if(delParent->right == delNode)
                delParent->right = child;
            
            delete delNode;
            return root;
        }

        else
        {
            TreeNode* succParent = delNode;
            TreeNode* succ = delNode->right;

            while(succ ->left != NULL)
            {
                succParent = succ;
                succ = succ->left;
            } 

            delNode->val = succ->val;

            if(succParent->left == succ)
            {
                succParent->left = succ->right;
            }
            else
            {
                succParent->right = succ->right;
            }

              delete succ;
            return root; 

        }

       
    }
};