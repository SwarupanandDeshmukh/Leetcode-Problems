class Solution {
  public:
    
    int find(int x, vector<int> &parent)
    {
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x], parent);
    }
    
    
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        
        sort(edges.begin(), edges.end(),
            [](const vector<int> &a, const vector<int> &b)
            {
                return a[2] < b[2];
            });
            
        
        int n = edges.size();
        
        vector<int> parent(V);
        vector<int> rank(V);
        
        for(int i = 0; i<V; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
        
        int cost = 0;
        for(int i = 0; i<n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            int parU = find(u, parent);
            int parV = find(v, parent);
            
            if(parU != parV)
            {
                cost = cost + wt;
                if(rank[parU] == rank[parV])
                {
                    parent[parV] = parU;
                    rank[parU]++;
                }
                else if(rank[parU] < rank[parV])
                {
                    parent[parU] = parV;
                }
                else
                {
                    parent[parV] = parU;
                }
            }
        }
        
        return cost;
    }
};