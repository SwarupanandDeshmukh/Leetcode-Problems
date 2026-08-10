class Solution {
  public:
  
    int helper(vector<vector<int>>& mat, int day, int last, vector<vector<int>> &dp)
    {
        if(day == 0)
        {
            int maxi = 0;
            for(int i = 0; i<3; i++)
            {
                if(i != last)
                {
                    maxi = max(maxi, mat[0][i]);    
                }
            }
            
            return maxi;
        }
        
        if(dp[day][last] != -1)
        {
            return dp[day][last];
        }
        
        int maxi = 0;
        for(int i = 0; i<3; i++)
        {
            if(i != last)
            {
                int pt = mat[day][i] + helper(mat, day-1, i, dp);    
                maxi = max(maxi, pt);

            }
        }
        
        return dp[day][last] = maxi;
        
    }
    
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
         int n = mat.size();
         
         vector<vector<int>> dp(n, vector<int> (4, -1));
        
        return helper(mat, n-1, 3, dp);
    }
};