class Solution {
public:

    void dfshelper(int start, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
    {
        visited[start] = true;

        for(const auto neigh: adj[start])
        {
            if(!visited[neigh])
                dfshelper(neigh, visited, adj);
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        unordered_map<int, list<int>> adj;
    

        for(const auto edge: edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[v].push_back(u);
        }

        vector<vector<int>> res(n);
        unordered_map<int,bool> visited;

        for(int i = 0;i<n; i++)
        {
            visited.clear();

            if(!visited[i])
            {
                dfshelper(i, visited, adj);
                for(int j = 0; j<n; j++)
                {
                    if(j!=i && visited[j])
                        res[i].push_back(j);
                }

            }
        }

        return res;

        


    }
};