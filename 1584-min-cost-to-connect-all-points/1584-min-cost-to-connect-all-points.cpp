class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);

        for(int i = 0; i<n; i++)
        {
            for(int j =i+1; j<n; j++)
            {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

                adj[i].push_back({j,dist}); 
                adj[j].push_back({i, dist});
            }
        }

        vector<bool> visited(n, false);

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