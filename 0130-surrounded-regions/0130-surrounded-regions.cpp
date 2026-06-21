class Solution {
public:

    bool valid(int x, int y, int m, int n)
    {
        if(x>=0 && x<m && y>=0 && y<n)
            return true;
        return false;
    }

    void dfshelper(int sr, int sc, vector<vector<bool>> &visited,vector<vector<char>>& board, int m, int n)
    {   
        visited[sr][sc] = true;
        board[sr][sc] = 'A';

        if(valid(sr+1,sc,m,n) && board[sr+1][sc] == 'O' && !visited[sr+1][sc])
        {
            dfshelper(sr+1, sc, visited, board,m,n);
        }

        if(valid(sr-1,sc,m,n) && board[sr-1][sc] == 'O' && !visited[sr-1][sc])
        {
            dfshelper(sr-1, sc, visited, board,m,n);
        }

        if(valid(sr,sc+1,m,n) && board[sr][sc+1] == 'O' && !visited[sr][sc+1])
        {
            dfshelper(sr, sc+1, visited, board,m,n);
        }

        if(valid(sr,sc-1,m,n) && board[sr][sc-1] == 'O' && !visited[sr][sc-1])
        {
            dfshelper(sr, sc-1, visited, board,m,n);
        }

    }


    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool> (n, false));

        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && board[i][j] == 'O' && !visited[i][j])
                {
                    dfshelper(i,j,visited,board,m,n);
                }
            }
        }

         for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(board[i][j] =='O')
                    board[i][j] = 'X';
                
                if(board[i][j] == 'A')
                    board[i][j] = 'O';
                
            }
        }
    }
};