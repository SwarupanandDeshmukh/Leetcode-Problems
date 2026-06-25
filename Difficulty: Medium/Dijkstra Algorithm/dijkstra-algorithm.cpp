class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        
        vector<vector<pair<int, int>>> adj(V);
        
        for(const auto edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int> dis(V, INT_MAX);
        
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        
        pq.push({0,src});
        dis[src] = 0;
        
        while(!pq.empty())
        {
            const auto [currdist, node] = pq.top();
            pq.pop();
            
            if(currdist > dis[node])
                continue; 
            
            for(const auto &[v, ndist]: adj[node])
            {
                if(dis[v] > dis[node] + ndist)
                {
                    dis[v] = dis[node] + ndist;
                    pq.push({dis[v],v});
                }
            }
        }
        
        return dis;
        
        
    }
};