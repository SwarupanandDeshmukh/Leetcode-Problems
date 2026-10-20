/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root == NULL)
            return "";

        string s = "";

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();

            if(temp == NULL)
            {
               s += "#,";
               continue;
            }
            else
            {
                s = s + to_string(temp->val) + ",";
                    q.push(temp->left);

                    q.push(temp->right);
            }
        }

        s.pop_back();
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        // 1,2,3,#,#,4,5,#,#,#,#

        if(data == "")
            return NULL;
        
        stringstream ss(data);
        string val;
        queue<TreeNode*> q;
        getline(ss, val, ',');
        TreeNode* root = new TreeNode(stoi(val));
        q.push(root);

        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();

            if(getline(ss, val, ','))
            {
                if(val != "#")
                {
                    TreeNode* lchild = new TreeNode(stoi(val));
                    temp->left = lchild;
                    q.push(lchild);
                }
            }

            if(getline(ss, val, ','))
            {
                if(val != "#")
                {
                    TreeNode* rchild = new TreeNode(stoi(val));
                    temp->right = rchild;
                    q.push(rchild);
                }
            }
        }

        return root;


    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));