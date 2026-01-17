class NumMatrix {
public:
    vector<vector<int>> v;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        v.resize(m, vector<int> (n, 0));
        v[0][0] = matrix[0][0];
        
        //TOP
        for(int j = 1; j<n; j++)
        {
            v[0][j] = v[0][j-1] + matrix[0][j];
        }

        //LEFT
        for(int i = 1; i<m; i++)
        {
            v[i][0] = v[i-1][0] + matrix[i][0];
        }

        //Filling inner cells
        for(int i = 1; i<m; i++)
        {
            for(int j = 1; j<n; j++)
            {
                v[i][j] = matrix[i][j] + v[i][j-1] + v[i-1][j] - v[i-1][j-1];
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
      int total = v[row2][col2];
    
    if (row1 > 0) {
        total -= v[row1 - 1][col2];
    }
    
    if (col1 > 0) {
        total -= v[row2][col1 - 1];
    }
    
    if (row1 > 0 && col1 > 0) {
        total += v[row1 - 1][col1 - 1];
    }
    
    return total;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */