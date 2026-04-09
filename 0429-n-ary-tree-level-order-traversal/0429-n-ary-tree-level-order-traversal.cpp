/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {

        if(root == NULL)
            return {};
        
        vector<vector<int>> res;
        vector<int> inner;

        queue<Node* > q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();

            if(temp == NULL)
            {
                res.push_back(inner);
                inner.clear();
                if(q.empty())
                    break;
                q.push(NULL);
            }
            else
            {
                inner.push_back(temp->val);
                for(Node* v: temp->children)
                    q.push(v);
            }
        }

        return res;

    }
};