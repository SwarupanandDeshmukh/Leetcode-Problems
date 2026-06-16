class Solution {
public:
     unordered_map<int, list<int>> adj;

    void dfshelper(int start, unordered_map<int, bool> &visited, unordered_map<int, bool> &rec, int &f)
    {
        visited[start] = true;
        rec[start] = true;
        
        for(const auto neigh : adj[start])
        {
            if(!visited[neigh])
                dfshelper(neigh, visited,rec, f);
            else if(rec[neigh])
            {
                f = 1;
                return;
            }
        }
        rec[start] = false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, bool> visited;
        unordered_map<int, bool> rec;

        for(const auto& pre : prerequisites)
        {
            int u = pre[0];
            int v = pre[1];
            adj[u].push_back(v);
        }

        int f = 0;
        for(const auto pair: adj)
        {
            if(!visited[pair.first])
                dfshelper(pair.first, visited, rec, f);
        }

        if(f == 1)
            return false;
        else
            return true;

    }
};