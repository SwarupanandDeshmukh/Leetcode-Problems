class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        // we can reverse the graph.
        unordered_map<int, list<int>> adj;
        unordered_map<int, int> indegree;

        int n = graph.size();

        for(int i = 0; i<n; i++)
        {
            indegree[i] = 0;
        }

        for(int i = 0; i<n; i++)
        {
                for(int j = 0; j<graph[i].size(); j++)
                {
                    adj[graph[i][j]].push_back(i);
                    indegree[i]++;
                }
        }

        queue<int> q;
        for(const auto pair: indegree)
        {
            if(pair.second == 0)
                q.push(pair.first);
        }

        vector<int> res;

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            res.push_back(curr);

            for(const auto neigh: adj[curr])
            {
                indegree[neigh]--;
                if(indegree[neigh] == 0)
                    q.push(neigh);
            }
            
        }

        sort(res.begin(), res.end());
        return res;

    }
};