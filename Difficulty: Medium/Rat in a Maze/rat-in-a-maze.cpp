class Solution {
  public:
  
    void helper(vector<vector<int>>& maze, int row, int col, string path, vector<string> &res, vector<vector<bool>> &visited)
    {
        if(row < 0 || col <0 || row >=maze.size() || col >= maze[0].size())
            return;
        
        if(maze[row][col] == 0)
            return;
        
        if(row == maze.size() -1 && col == maze[0].size() - 1)
        {
            res.push_back(path);
            return;
        }
        
        if(visited[row][col] == true)
            return;
        
        
        visited[row][col] = true;
        helper(maze, row+1,col, path + "D", res, visited);
        helper(maze, row-1,col, path + "U", res, visited);
        helper(maze, row,col-1, path + "L", res, visited);
        helper(maze, row,col+1, path + "R", res, visited);
        
        visited[row][col] = false;
        
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        
        int m = maze[0].size();
        int n = maze.size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        vector<string> res;
        string path = "";
    
        
        if(maze[0][0] == 0 || maze[n-1][m-1] == 0)
            return {};
            
        helper(maze, 0,0, path, res, visited);
        
        sort(res.begin(), res.end());
        
        return res;
        
        
    }
};