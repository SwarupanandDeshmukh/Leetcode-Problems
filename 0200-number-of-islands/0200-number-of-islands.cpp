class Solution {
public:

    bool valid(int x, int y, int m, int n)
    {
        if(x>=0 && x<m && y>=0 && y<n)
            return true;
        return false;
    }

    void dfshelper(int sr, int sc,map<pair<int, int>, bool> &visited,vector<vector<char>> &grid, int m, int n)
    {
        visited[{sr,sc}] = true;

        //calling the function recursively for neighbours.

        if(valid(sr+1,sc,m,n) && grid[sr+1][sc] == '1' && !visited[{sr+1,sc}])
        {
            dfshelper(sr+1,sc, visited, grid, m ,n);
        }

        if(valid(sr-1, sc, m,n) && grid[sr-1][sc] == '1' && !visited[{sr-1,sc}])
        {
            dfshelper(sr-1,sc, visited, grid, m ,n);
        }

        if(valid(sr,sc+1,m,n) && grid[sr][sc+1] == '1' && !visited[{sr,sc+1}])
        {
            dfshelper(sr,sc+1, visited, grid, m ,n);
        }

        if(valid(sr,sc-1,m,n) && grid[sr][sc-1] == '1' && !visited[{sr,sc-1}])
        {
            dfshelper(sr,sc-1, visited, grid, m ,n);
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        map<pair<int, int>, bool> visited;
        int cnt = 0;

        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(grid[i][j] == '1' && !visited[{i,j}])
                {
                    dfshelper(i,j,visited,grid, m, n);
                    cnt++;
                }
            }
        } 

        return cnt;

    }
};