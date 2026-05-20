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

        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            if(temp == NULL)
            {
                s += "N";
            }
            else
            {
                s += to_string(temp->val);
                q.push(temp->left);
                q.push(temp->right);
            }

            s += ",";

        }

        s.pop_back();
        cout<<s <<endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data == "")
            return NULL;
        
        stringstream ss(data);
        string parts;
        vector<string> v;

        while(getline(ss, parts, ','))
        {
            v.push_back(parts);
        }

        TreeNode* root = new TreeNode(stoi(v[0]));
        int i = 1;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty() && i < v.size())
        {
            TreeNode *tmp = q.front();
            q.pop();

            if(i < v.size() && v[i] != "N")
            {
                TreeNode* leftNode = new TreeNode(stoi(v[i]));
                tmp->left = leftNode;
                q.push(leftNode);
            }
            i++;

            if(i < v.size() && v[i] != "N")
            {
                TreeNode* rightNode = new TreeNode(stoi(v[i]));
                tmp->right = rightNode;
                q.push(rightNode);
            }
            i++;

        }

        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));