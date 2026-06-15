class Solution {
  public:
  
    void dfshelper(int start, unordered_map<int, bool> &visited, vector<int> &res, vector<vector<int>>& adj)
    {
        visited[start] = true;
        
        res.push_back(start);
        
        for(const auto neigh : adj[start])
        {
            if(!visited[neigh])
                dfshelper(neigh, visited, res, adj);
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        
        unordered_map<int, bool> visited;
        vector<int> res;
        dfshelper(0, visited, res, adj);
        return res;
        
    }
};