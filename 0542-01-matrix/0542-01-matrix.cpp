class Solution {
public:

    bool valid(int x, int y, int m, int n)
    {
        if(x>=0 && x<m && y>=0 && y<n)
            return true;
        return false;
    }

    void bfshelper(queue<pair<int, int>> &q, vector<vector<int>>& mat, vector<vector<int>> &res, int m, int n)
    {
       
        while(!q.empty())
        {
            const auto corr = q.front();
            q.pop();

            int x = corr.first;
            int y = corr.second;
            

            if(valid(x+1, y, m,n) && res[x+1][y] == -1)
            {
                res[x+1][y] = res[x][y] + 1;
                q.push({x+1,y});
            } 

             if(valid(x-1, y, m,n) && res[x-1][y] == -1)
            {
                res[x-1][y] = res[x][y] + 1;
                q.push({x-1,y});
            } 

             if(valid(x, y+1, m,n) && res[x][y+1] == -1)
            {
                res[x][y+1] = res[x][y] + 1;
                q.push({x,y+1});
            } 

             if(valid(x, y-1, m,n) && res[x][y-1] == -1)
            {
                res[x][y-1] = res[x][y] + 1;
                q.push({x,y-1});
            } 
            
        }

    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> res(m, vector<int> (n, -1));
        queue<pair<int, int>> q;

        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(mat[i][j] == 0)
                {
                    res[i][j] = 0;
                    q.push({i,j});
                }
            }
        }   

        bfshelper(q,mat, res, m,n);

        return res;
        
    }
};