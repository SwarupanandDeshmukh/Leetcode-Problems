class Solution {
public:

    bool valid(int x, int y, int m , int n)
    {
        if(x >= 0 && x < m && y >=0 && y < n)
            return true;
        return false;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        queue<pair<int, int>> q;
        map<pair<int, int>, bool> visited;

        int m = image.size();
        int n = image[0].size();

        int orgcolor = image[sr][sc];

        q.push({sr,sc});
        visited[{sr,sc}] = true;

        while(!q.empty())
        {
            const auto coor = q.front();
            q.pop();

            int x = coor.first;
            int y = coor.second;

            if(image[x][y] == orgcolor)
                image[x][y] = color;
            
            if(valid(x+1,y,m,n) && image[x+1][y] == orgcolor && !visited[{x+1,y}])
            {
                q.push({x+1,y});
                visited[{x+1, y}] = true;
            }

            if(valid(x-1,y,m,n) && image[x-1][y] == orgcolor && !visited[{x-1,y}])
            {
                q.push({x-1,y});
                visited[{x-1, y}] = true;
            }

            if(valid(x,y+1,m,n) && image[x][y+1] == orgcolor && !visited[{x,y+1}])
            {
                q.push({x,y+1});
                visited[{x, y+1}] = true;
            }

            if(valid(x,y-1,m,n) && image[x][y-1] == orgcolor && !visited[{x,y-1}])
            {
                q.push({x,y-1});
                visited[{x, y-1}] = true;
            }

        }

        return image;
    }
};