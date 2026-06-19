class Solution {
public:
    unordered_map<int, list<int>> adj;

    void dfshelper(int start, unordered_map<int, bool> &visited)
    {
        visited[start] = true;

        for(const auto neigh : adj[start])
        {
            if(!visited[neigh])
                dfshelper(neigh, visited);
        }
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(isConnected[i][j] == 1)
                {
                    adj[i+1].push_back(j+1);
                }
            }
        }

        unordered_map<int, bool> visited;
        int cnt = 0;

        for(const auto pair: adj)
        {

            if(!visited[pair.first])
            {
                cnt++;
                dfshelper(pair.first, visited);
                
            }
             

        }

        return cnt;
    }
};