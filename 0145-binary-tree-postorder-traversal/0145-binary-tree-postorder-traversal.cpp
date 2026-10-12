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
    vector<int> postorderTraversal(TreeNode* root) {
        
        TreeNode *temp = root;

        vector<int> res;
        stack<TreeNode *> st;

        TreeNode* last = NULL;
        while(temp != NULL || !st.empty())
        {
            if(temp != NULL)
            {
                st.push(temp);
                temp = temp->left;
            }
            else
            {
                TreeNode *node = st.top();

                if(node->right != NULL && node->right != last)
                {
                    temp = node->right;
                }
                else
                {
                    res.push_back(node->val);
                    st.pop();
                    last = node;
                }
            }

        }

         return res;
    }
};