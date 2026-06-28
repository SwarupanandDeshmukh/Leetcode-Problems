class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(const auto f: flights)
        {
            int u = f[0];
            int v = f[1];
            int w = f[2];

            adj[u].push_back({v,w});
        }

        vector<vector<int>> dis(n, vector<int> (k+2, INT_MAX));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {src, 0}});
        dis[src][0] = 0;

        while(!pq.empty())
        {
            const auto pair = pq.top();
            pq.pop();

            int currdist = pair.first;
            int node = pair.second.first;
            int cnt = pair.second.second;

            if(cnt > k)
                continue;
            
            for(const auto [v, vdist] : adj[node])
            {
                if(dis[v][cnt+1] > currdist + vdist)
                {
                    dis[v][cnt+1] = currdist + vdist;
                    pq.push({dis[v][cnt+1], {v, cnt+1}});
                }
            }
        }
        
        int mini = INT_MAX;
        for(int i = 0; i<dis[dst].size(); i++)
        {
            if(dis[dst][i] < mini)
                mini = dis[dst][i];
        }

        if(mini == INT_MAX)
            return -1;
        
        return mini;
    }
};