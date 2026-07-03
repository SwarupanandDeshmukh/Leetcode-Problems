class Solution {
public:

    void dfshelper(int start, vector<bool> &visited, unordered_map<int, vector<int>> &adj, int parent, vector<int> &e, vector<vector<int>> &res, vector<int> &dt, vector<int> &low, int &t)
    {
        visited[start] = true;
        dt[start] = ++t;
        low[start] = dt[start];

        for(const auto neigh: adj[start])
        {
            if(!visited[neigh])
            {   
                dfshelper(neigh, visited,adj, start, e, res, dt, low, t);
                low[start] = min(low[start], low[neigh]);
                if(low[neigh] > dt[start])
                {
                    e.push_back(start);
                    e.push_back(neigh);
                    res.push_back(e);
                    e.clear();
                }
                
            }
            else if(neigh != parent)
            {
                low[start] = min(low[start], dt[neigh]);  
            }
        }
        
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        unordered_map<int, vector<int>> adj;

        for(const auto con : connections)
        {
            int u = con[0];
            int v = con[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        vector<int> e;
        vector<vector<int>> res;
        vector<int> dt(n, 0);
        vector<int> low(n, 0);
        int t = 0;
        dfshelper(0, visited,adj, -1, e, res, dt, low, t);

        return res;
    }
};