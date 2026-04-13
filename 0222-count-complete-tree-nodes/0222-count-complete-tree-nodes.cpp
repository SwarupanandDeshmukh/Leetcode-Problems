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
    int countNodes(TreeNode* root) {
        // if(root == NULL)
        //     return 0;
        
        // queue<TreeNode* > q;
        // int cnt = 0;
        // q.push(root);

        // while(!q.empty())
        // {
        //     TreeNode* temp = q.front();
        //     q.pop();

        //     cnt++;

        //     if(temp->left)
        //         q.push(temp->left);
            
        //     if(temp->right)
        //         q.push(temp->right);

        // }

        // return cnt;

        if(root == NULL)
            return 0;
        int leftcnt = leftCount(root);
        int rightcnt = rightCount(root);

        if(leftcnt == rightcnt)
            return (int) pow(2, leftcnt) - 1;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);

     }

     int leftCount(TreeNode *root)
     {
        int d = 0;
        while(root != NULL)
        {
            root = root->left;
            d++;
        }

        return d;
    
     }

     int rightCount(TreeNode *root)
     {
        int d = 0;
        while(root != NULL)
        {
            root = root->right;
            d++;
        }

        return d;
    
     }
};