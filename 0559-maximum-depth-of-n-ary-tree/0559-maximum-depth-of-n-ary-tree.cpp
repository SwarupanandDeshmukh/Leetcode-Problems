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
    int maxDepth(Node* root) {
        if(root == NULL)
        {
            return 0;
        }

        queue<Node* > q;
        int cnt = 0;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();

            if(temp == NULL)
            {
                cnt++;
                if(q.empty())
                    break;
                q.push(NULL);
            }   
            else
            {         
                for(Node* v : temp->children)
                {
                    q.push(v);
                }

            }
        
        }

        return cnt;

    }
};