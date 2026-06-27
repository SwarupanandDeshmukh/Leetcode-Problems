class Solution {
public:

    bool valid(int x, int y, int n)
    {
        if(x>=0 && x<n && y>=0 && y<n)
            return true;
        return false;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        

        queue<pair<pair<int, int>, int>> q;
        
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        q.push({{0,0},0});
        visited[0][0] = true;
        vector<pair<int, int>> path;

        int cnt = 0;
        while(!q.empty())
        {
            const auto coor = q.front();
            q.pop();

            int x = coor.first.first;
            int y = coor.first.second;
            int d = coor.second;
            

            if(x == n-1 && y == n-1)
                return d+1;

            if(valid(x+1,y+1,n) && grid[x+1][y+1]==0 && !visited[x+1][y+1])
            {
                q.push({{x+1,y+1}, d+1});
                visited[x+1][y+1] = true;
            }

            if(valid(x+1,y-1,n) && grid[x+1][y-1]==0 && !visited[x+1][y-1])
            {
                q.push({{x+1,y-1}, d+1});
                visited[x+1][y-1] = true;
            }

            if(valid(x-1,y-1,n) && grid[x-1][y-1]==0 && !visited[x-1][y-1])
            {
                q.push({{x-1,y-1}, d+1});
                visited[x-1][y-1] = true;
            }

            if(valid(x-1,y+1,n) && grid[x-1][y+1]==0 && !visited[x-1][y+1])
            {
                q.push({{x-1,y+1}, d+1});
                visited[x-1][y+1] = true;
            }

            if(valid(x+1,y,n) && grid[x+1][y]==0 && !visited[x+1][y])
            {
                q.push({{x+1,y}, d+1});
                visited[x+1][y] = true;
            }

            if(valid(x-1,y,n) && grid[x-1][y]==0 && !visited[x-1][y])
            {
                q.push({{x-1,y}, d+1});
                visited[x-1][y] = true;
            }

            if(valid(x,y+1,n) && grid[x][y+1]==0 && !visited[x][y+1])
            {
                q.push({{x,y+1}, d+1});
                visited[x][y+1] = true;
            }

            if(valid(x,y-1,n) && grid[x][y-1]==0 && !visited[x][y-1])
            {
                q.push({{x,y-1}, d+1});
                visited[x][y-1] = true;
            }

            
        }

        return -1;



    }
};