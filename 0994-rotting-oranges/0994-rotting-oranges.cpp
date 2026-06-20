class Solution {
public:

    bool valid(int x, int y, int m, int n)
    {
        if(x>=0 && x < m && y >=0 && y<n)
            return true;
        return false;

    }

    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int f = 0;
        int cnt = 0;

        queue<pair<pair<int,int>, int>> q;
        map<pair<int, int>, bool> visited;


        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j}, 0});
                    visited[{i,j}] = true;
                }
            }

        }

        while(!q.empty())
        {
            const auto coor = q.front();
            q.pop();

            int x = coor.first.first;
            int y = coor.first.second;
            int time = coor.second;

            cnt = max(cnt , time);

            if(grid[x][y] == 1)
                grid[x][y] = 2;
            
            if(valid(x+1,y,m,n) && grid[x+1][y] == 1 && !visited[{x+1,y}])
            {
                q.push({{x+1,y}, time + 1});
                visited[{x+1,y}] = true;
            }

            if(valid(x-1,y,m,n) && grid[x-1][y] == 1 && !visited[{x-1,y}])
            {
                q.push({{x-1,y}, time + 1});
                visited[{x-1,y}] = true;
            }

            if(valid(x,y+1,m,n) && grid[x][y+1] == 1 && !visited[{x,y+1}])
            {
                q.push({{x,y+1}, time + 1});
                visited[{x,y+1}] = true;
            }

            if(valid(x,y-1,m,n) && grid[x][y-1] == 1 && !visited[{x,y-1}])
            {
                q.push({{x,y-1}, time + 1});
                visited[{x,y-1}] = true;
            }
    
        }

        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }

        }

        return cnt;

    }
};