class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        if(n == 1)
            return 1;
        
        unordered_map<int, list<int>> adj;

        for(const auto edge : trust)
        {
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u);

        }
    
        int key = 0;
        for(const auto pair: adj)
        {
            if(pair.second.size() == n-1)
                 key = pair.first;
            
        }

        if(key == 0)
            return -1;

        if(adj.size() == 1)
            return key;

        int f = 0;
        if(key != 0)
        {
            for(const auto pair : adj)
            {
                if(find(pair.second.begin(), pair.second.end(), key) != pair.second.end())
                {
                    f = 1;
                    break;
                }
            }
        }

        if(f == 1)
            return -1;


        return key;
    }
};