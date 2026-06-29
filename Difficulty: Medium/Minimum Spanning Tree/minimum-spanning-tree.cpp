class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<vector<pair<int, int>>> adj(V);
        
        for(const auto edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<bool> visited(V, false);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0,0});
        
        int cost = 0;
        
        while(!pq.empty())
        {
            const auto [wt, node] = pq.top();
            pq.pop();
            
            if(!visited[node])
            {
                visited[node] = true;
                cost = cost + wt;
                
                for(const auto [neigh, neigh_wt] : adj[node])
                {
                    pq.push({neigh_wt, neigh});
                }
                
            }
        }
        
        return cost;
    }
};