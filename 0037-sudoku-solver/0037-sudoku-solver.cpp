class Solution {
public:

    bool safe(vector<vector<char>>& board, int row, int col, int digit)
    {

        for(int i = 0; i<9; i++)
        {
            if(board[i][col] == digit)
                return false;
        }


        for(int j = 0; j<9; j++)
        {
            if(board[row][j] == digit)
                return false;
        }

        int sr = (row/3) * 3;
        int sc = (col/3) * 3;

        for(int i = sr; i<=sr+2; i++)
        {
            for(int j = sc; j<=sc+2; j++)
            {
                if(board[i][j] == digit)
                    return false;
            }
        }


        return true;


    }
    bool helper(vector<vector<char>>& board)
    {
        for(int i = 0; i<9; i++)
        {
            for(int j = 0; j<9;j++)
            {
                if(board[i][j] == '.')
                {
                    for(char dig = '1'; dig<='9'; dig++)
                    {
                        if(safe(board, i,j,dig))
                        {
                            board[i][j] = dig;
                            if(helper(board))
                                return true;
                            
                            board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        helper(board);
    }
};