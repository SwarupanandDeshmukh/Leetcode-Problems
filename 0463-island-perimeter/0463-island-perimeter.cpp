class Solution {
public: 


    void dfshelper(int x, int y, vector<vector<int>>& grid, int &perimeter)
    {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
        {
            perimeter++;
            return;
        }
        
        if(grid[x][y] == 0)
        {
            perimeter++;
            return;
        }

        if(grid[x][y] == -1)
            return;
        
        grid[x][y] = -1;

        
        dfshelper(x-1,y, grid, perimeter);
        dfshelper(x+1,y, grid, perimeter);
        dfshelper(x,y-1, grid, perimeter);
        dfshelper(x,y+1, grid, perimeter);

    }

    int islandPerimeter(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        int x = 0, y = 0;
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    x = i;
                    y = j;
                    break;
                }
            }
        }

        int perimeter = 0;
        dfshelper(x,y, grid, perimeter);

        return perimeter;
    }
};