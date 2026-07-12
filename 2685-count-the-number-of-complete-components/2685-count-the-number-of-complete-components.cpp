class Solution {
public:

    void dfshelper(int start, unordered_map<int, vector<int>> &adj, vector<bool> &visited, int &e, int &nodes)
    {
        visited[start] = true;
        nodes++;

        for(const auto neigh: adj[start])
        {
            e++;
            if(!visited[neigh])
            {
                dfshelper(neigh, adj, visited, e, nodes);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        unordered_map<int, vector<int>> adj;

        int m = edges.size();

        for(int i = 0; i<m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        int cnt = 0;
        int nodes = 0, e = 0;
        for(int i = 0; i<n; i++)
        {
            if(!visited[i])
            {
                dfshelper(i, adj, visited, e, nodes);
                int val = (nodes*(nodes-1)) / 2;
                if((e/2) == val)
                    cnt++;
            }
            e = 0;
            nodes = 0;
        }

        return cnt;
    }
};