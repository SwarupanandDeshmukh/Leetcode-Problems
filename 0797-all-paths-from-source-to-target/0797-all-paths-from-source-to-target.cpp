class Solution {
public:

    void dfshelper(int src, int dest, vector<int> &path, vector<vector<int>> &res, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
    {
        visited[src] = true;
        path.push_back(src);

        if(src == dest)
        {
            res.push_back(path);
        }

        for(const auto neigh: adj[src])
        {
            if(!visited[neigh])
                dfshelper(neigh, dest, path, res, visited, adj);
        }

        visited[src] = false;
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();
        unordered_map<int, list<int>> adj;
        for(int i = 0; i<n; i++)
        {
            if(graph[i].size() == 0)
                adj[i].push_back({});
            else
            {
                for(int j = 0; j<graph[i].size(); j++)
                {
                    adj[i].push_back(graph[i][j]);
                }
            }
        }

        vector<int> path;
        vector<vector<int>> res;
        unordered_map<int, bool> visited;
        dfshelper(0, n-1, path, res, visited, adj);

        return res;


    }
};