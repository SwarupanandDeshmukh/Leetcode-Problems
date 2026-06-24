class Solution {
  public:
    

    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        
        unordered_map<int, list<int>> adj;
        unordered_map<int, int> indegree;
        
        for(int i = 0; i<V; i++)
        {
            indegree[i] = 0;
        }
        
        for(const auto edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        
        queue<int> q;
        
        for(const auto pair: indegree)
        {
            if(pair.second == 0)
                q.push(pair.first);
        }
        
        vector<int> res;
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            res.push_back(curr);
            
            for(const auto neigh: adj[curr])
            {
                indegree[neigh]--;
                if(indegree[neigh] == 0)
                    q.push(neigh);
            }
        }
        
        return res;
        
        
    }
};