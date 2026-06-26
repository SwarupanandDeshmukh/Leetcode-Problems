class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int, int>>> adj(n);

        for(const auto edge: roads)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<long long> dis(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        pq.push({0, 0});
        dis[0] = 0;
        ways[0] = 1;

        const long val = 1e9 + 7;
        while(!pq.empty())
        {
            const auto [currdist, node] = pq.top();
            pq.pop();

            if(currdist > dis[node])
                continue;
            
            for(const auto [v, vdist] : adj[node])
            {
                if(dis[v] > dis[node] + vdist)
                {
                    dis[v] = dis[node] + vdist;
                    ways[v] = ways[node];
                    pq.push({dis[v], v});
                }
                else if(dis[v] == dis[node] + vdist)
                    ways[v]  = (ways[v] + ways[node]) % val;
            }
        }

        int cnt = ways[n-1];
        return cnt;

        

    }
};