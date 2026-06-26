class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> adj(n+1);

        for(const auto edge: times)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
        }

        vector<int> dis(n+1, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0,k});
        dis[k] = 0;

        while(!pq.empty())
        {
            auto [currdist, node] = pq.top();
            pq.pop();

            if(currdist > dis[node])
                continue;

            for( auto [v, vdist] : adj[node])
            {
                if(dis[v] > dis[node] + vdist)
                {
                    dis[v] = dis[node] + vdist;
                    pq.push({dis[v], v});
                }
            }
        }

       int maxi = 0;
       for(int  i =1; i<dis.size(); i++)
       {
            if(dis[i] == INT_MAX)  
                return -1;
            maxi = max(maxi, dis[i]);
       }

        return maxi;

    }
};