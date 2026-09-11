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

    pair<int, int> helper(TreeNode* root, int &cnt)
    {
        if(root == NULL)
            return {0,0};
        
        pair<int,int> left = helper(root->left, cnt);
        pair<int, int> right = helper(root->right, cnt);
    
        int totalsum = left.first + right.first + root->val;
        int totalcount = left.second + right.second + 1;

        if(totalsum / totalcount == root->val)
            cnt++;
        
        return {totalsum, totalcount};
    }

    int averageOfSubtree(TreeNode* root) {
        
        int cnt = 0;
        pair<int, int> p = helper(root, cnt);

        return cnt;

    }
};