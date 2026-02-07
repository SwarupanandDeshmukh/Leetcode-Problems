class Solution {
public:

    bool safe(vector<string> &board, int row, int col, int n)
    {
        //check vertically.
        for(int i = 0; i<n; i++)
        {
            if(board[i][col] == 'Q')
                return false;
        }


        //check horizontally.
        for(int i = 0; i<n; i++)
        {
            if(board[row][i] == 'Q')
                return false;
        }

        //check left diagonal
        for(int i = row, j = col; i>=0 && j>=0; i--,j--)
        {
            if(board[i][j] == 'Q')
                return false;
        }

        //check right diagonal
        for(int i = row, j = col; i>=0 && j<n; i--,j++)
        {
            if(board[i][j] == 'Q')
                return false;
        }

        return true;


    }

    void helper(vector<string> &board, int n, int row, vector<vector<string>> &res)
    {
        if(row == n)
        {
            res.push_back(board);
            return;
        }

        for(int i = 0; i<n; i++)
        {
            if(safe(board,row,i,n))
            {
                board[row][i] = 'Q';
                helper(board, n, row+1, res);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        vector<vector<string>> res;

        helper(board, n, 0, res);

        return res;

    }
};