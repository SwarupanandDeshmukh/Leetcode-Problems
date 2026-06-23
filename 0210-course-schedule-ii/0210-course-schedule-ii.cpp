class Solution {
public:

    bool hasCycle(int start, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<bool> &path)
    {
            visited[start] = true;
            path[start] = true;

            for(const auto neigh: adj[start])
            {
                if(!visited[neigh])
                {
                    if(hasCycle(neigh, visited, adj, path))
                        return true;
                }
                else if(path[neigh])
                {
                    return true;
                }   
            }
        
        path[start] = false;
        return false;
    }


    void dfshelper(int start, unordered_map<int, bool> &visited, stack<int> &s,unordered_map<int, list<int>> &adj)
    {
        visited[start] = true;

        for(const auto neigh: adj[start])
        {
            if(!visited[neigh])
                dfshelper(neigh, visited, s, adj);
        }

        s.push(start);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, list<int>> adj;
        unordered_map<int, bool> visited;

        for(const auto pre : prerequisites)
        {
            int u = pre[0];
            int v = pre[1];

            adj[v].push_back(u);
        }

        vector<bool> path(numCourses, false);
        for(int i = 0; i<numCourses; i++)
        {
            if(!visited[i])
            {
                if(hasCycle(i, visited, adj, path))
                    return {};
            }
        }

        visited.clear();


        stack<int> s;

        for(int i = 0; i<numCourses; i++)
        {
            if(!visited[i])
                dfshelper(i, visited, s, adj);
        }

        vector<int> res;
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }

    
        return res;


    }
};