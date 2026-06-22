class Solution {
public:

    bool valid(int x, int y, int m, int n)
    {
        if(x>=0 && x<m && y>=0 && y<n)
            return true;
        return false;
    }

    void dfshelper(int sr, int sc, vector<vector<bool>> &visited,vector<vector<int>>& grid, int m, int n)
    {
        visited[sr][sc] = true;
        grid[sr][sc] = 2;

        if(valid(sr+1,sc,m,n) && grid[sr+1][sc] == 1 && !visited[sr+1][sc])
            dfshelper(sr+1,sc,visited, grid, m,n);

        if(valid(sr-1,sc,m,n) && grid[sr-1][sc] == 1 && !visited[sr-1][sc])
            dfshelper(sr-1,sc,visited, grid, m,n);

        if(valid(sr,sc+1,m,n) && grid[sr][sc+1] == 1 && !visited[sr][sc+1])
            dfshelper(sr,sc+1,visited, grid, m,n);

        if(valid(sr,sc-1,m,n) && grid[sr][sc-1] == 1 && !visited[sr][sc-1])
            dfshelper(sr,sc-1,visited, grid, m,n);
        
    }

    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool> (n, false));
        
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && grid[i][j] == 1 && !visited[i][j])
                {
                    dfshelper(i,j,visited, grid, m,n);
                }
            }
        }

        int cnt = 0;

        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(grid[i][j] == 1)
                    cnt++;
            }
        }

        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(grid[i][j] == 2)
                    grid[i][j] = 1;
            }
        }

        return cnt;
    }
};