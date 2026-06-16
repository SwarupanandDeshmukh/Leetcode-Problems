class Solution {
public:
    unordered_map<int, list<int>> adj;

    int findCenter(vector<vector<int>>& edges) {
        
        int cnt = 0;
        for(const auto edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            cnt++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(const auto pair: adj)
        {
            if(pair.second.size() == cnt)
                return pair.first;
        }

        return 0;


    }
};