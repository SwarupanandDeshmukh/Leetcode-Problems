class Solution {
public:

    void dfshelper(int start, vector<bool> &visited, vector<vector<int>> &adj)
    {
        visited[start] = true;

        for(const auto neigh: adj[start])
        {
            if(!visited[neigh])
                dfshelper(neigh, visited, adj);
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();
        vector<vector<int>> adj(n);

        for(int i = 0; i<n; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                if((stones[i][0] == stones[j][0]) || stones[i][1] == stones[j][1])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);
        int cnt = 0;
        for(int i = 0; i< adj.size(); i++)
        {
            if(!visited[i])
            {
                dfshelper(i, visited, adj);
                cnt++;
            }
        }

        return n - cnt;





        
    }
};