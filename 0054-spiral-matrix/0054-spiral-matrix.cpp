class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int sr = 0;
        int sc = 0;
        int er = m -1;
        int ec = n - 1;
        vector<int> v;

        while(sc <= ec && sr <= er)
        {
            //TOP
            for(int i = sc; i<=ec; i++)
            {
                v.push_back(matrix[sr][i]);
            }

            //RIGHT
            for(int j = sr+1; j<=er; j++)
            {
                v.push_back(matrix[j][ec]);
            }

            //BOTTOM
            for(int i = ec-1; i>=sc; i--)
            {
                if(sr == er)
                {
                    break;
                }
                v.push_back(matrix[er][i]);
            }


            //LEFT
            for(int j = er-1; j>=sr+1; j--)
            {
                if(sc == ec)
                {
                    break;
                }
                v.push_back(matrix[j][sc]);
            }

            sc++;
            sr++;
            er--;
            ec--;
        }

       return v;
    }
};