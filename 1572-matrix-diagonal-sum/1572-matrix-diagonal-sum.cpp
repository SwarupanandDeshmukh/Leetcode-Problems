class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();

        int  psum = 0, ssum= 0;
        int f = 0;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(i==j)
                {
                    psum = psum + mat[i][j];
                }
                else if(j == n -i -1)
                {
                    ssum = ssum + mat[i][j];
                }

            }
        }

        return psum + ssum;

        
    }
};