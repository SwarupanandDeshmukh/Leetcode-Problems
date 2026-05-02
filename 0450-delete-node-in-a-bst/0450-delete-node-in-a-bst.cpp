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
        
        TreeNode *temp = root;
        TreeNode *parent = NULL;
        while(temp != NULL)
        {
            if(temp->val == key)
            {
                if(!temp->left && !temp->right)
                {
                    if(parent == NULL)
                    {
                        delete temp;
                        return NULL;
                    }

                    if(parent->left == temp)
                        parent->left = NULL;
                    if(parent->right == temp)
                        parent->right = NULL;
                    
                    delete temp;
                    return root;
                }

                else if(temp->left != NULL && temp->right == NULL)
                {
                    if(parent == NULL)
                    {
                        TreeNode *newroot = temp->left;
                        delete temp;
                        return newroot;
                    }
                    
                    if(parent->left == temp)
                        parent->left = temp->left;
                    if(parent->right == temp)
                        parent->right = temp->left;

                    delete temp;
                    return root;

                }
                else if(temp->right != NULL && temp->left == NULL)
                {
                    if(parent == NULL)
                    {
                        TreeNode *newroot = temp->right;
                        delete temp;
                        return newroot;
                    }
                    
                    if(parent->left == temp)
                        parent->left = temp->right;
                    if(parent->right == temp)
                        parent->right = temp->right;

                    delete temp;
                    return root;
                }
                else
                {
                    TreeNode *suc = temp->right;
                    TreeNode *sparent = temp;

                    while(suc->left != NULL)
                    {
                        sparent = suc;
                        suc = suc->left;
                    }



                    temp->val = suc->val;

                    if(sparent->left ==suc)
                        sparent->left = suc->right;
                    
                    else
                        sparent->right = suc->right;

                    delete suc;
                    return root;

                }
            }
            else if(key < temp->val)
            {
                parent = temp;
                temp = temp->left;
            }
            else
            {
                parent = temp;
                temp = temp->right;
            }
        }

        return root;
    }
};