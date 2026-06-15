class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        
        queue<int> q;
        unordered_map<int, bool> visited;
        vector<int> res;

        
        q.push(0);
        visited[0] = true;
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            res.push_back(curr);
            
            for(const auto neigh: adj[curr])
            {
                if(!visited[neigh])
                {
                    visited[neigh] = true;
                    q.push(neigh);
                }
            }
        }
        
        return res;
    }
};