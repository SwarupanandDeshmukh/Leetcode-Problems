class Solution {
public:

    bool dfshelper(unordered_map<int, list<int>> &adj,  unordered_map<int, bool> &visited, int s, int  t)
    {
        if(s == t)
            return true;

        visited[s] = true;

        

        for(const auto neigh: adj[s])
        {    
            if(!visited[neigh])
            {
                if(dfshelper(adj, visited, neigh, t))
                    return true;
            }
               
        }

        return false;

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
        vector<int> res;
        for(const auto edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            
            visited.clear();
            
            if(adj.find(u) != adj.end() && adj.find(v) != adj.end() && dfshelper(adj, visited, u, v))
            {
                return {u,v};
            }

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        return {};


    }
    
};