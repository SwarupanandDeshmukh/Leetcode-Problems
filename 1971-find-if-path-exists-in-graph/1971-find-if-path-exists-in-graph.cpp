class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        unordered_map<int, list<int>> adj;

        for(const auto edge: edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        map<int, bool> visited;
        q.push(source);
        visited[source] = true;

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            if(curr == destination)
                return true;
            
            for(const auto neigh: adj[curr])
            {
                if(!visited[neigh])
                {
                    visited[neigh] = true;
                    q.push(neigh);
                }
            }
        }

        return false;
        
    }
};