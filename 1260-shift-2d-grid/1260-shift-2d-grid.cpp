class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m, vector<int> (n ,0));

        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {   
                    int idx = i *n + j;
                    int newIdx = (idx + k) % (m * n);
                    int newr = newIdx/n;
                    int newc = newIdx % n;

                    res[newr][newc] = grid[i][j];

            }
        }

        return res;
    }
};