class Solution {
public:

    int find(int x, vector<int> &parent)
    {
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x], parent);
    }

    void dfshelper(int start, vector<bool> &visited, unordered_map<int, vector<int>> &adj)
    {
        visited[start] = true;

        for(const auto neigh: adj[start])
        {
            if(!visited[neigh])
                dfshelper(neigh, visited, adj);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        unordered_map<int, vector<int>> adj(n);
        for(const auto edge: connections)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        vector<bool> visited(n, false);
        int cnt = 0;
        for(int i = 0; i<n; i++)
        {
            if(!visited[i])
            {
                dfshelper(i, visited, adj);
                cnt++;
            }
                
        }

        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i = 0; i<n; i++)
        {
            parent[i] = i;
        }

        int extra = 0;
        for(const auto edge: connections)
        {
            int u = edge[0];
            int v = edge[1];

            int parU = find(u, parent);
            int parV = find(v, parent);

            if(parU == parV)
                extra++;
            else
            {
                if(rank[parU] == rank[parV])
                {
                    parent[parV] = parU; 
                    rank[parU]++;
                }
                else if(rank[parU] > rank[parV])
                     parent[parV] = parU;
                else
                    parent[parU] = parV;
            }
        }


        if(extra >= cnt -1)
            return cnt - 1;
        
        return -1;











    }
};