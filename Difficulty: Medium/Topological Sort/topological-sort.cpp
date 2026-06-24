class Solution {
  public:
    
    void topoSort(int start, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj)
    {
        visited[start] = true;
        
        for(const auto neigh: adj[start])
        {
            if(!visited[neigh])
                topoSort(neigh, visited, s, adj);
        }
        
        s.push(start); 
        
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        
        unordered_map<int, list<int>> adj;
        unordered_map<int, bool> visited;
        stack<int> s;
        
        for(const auto edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
        }
        
        for(int i = 0; i<V; i++)
        {
            if(!visited[i])
                topoSort(i, visited, s, adj);
        }
        
        
        vector<int> res;
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        
        return res;
        
        
    }
};