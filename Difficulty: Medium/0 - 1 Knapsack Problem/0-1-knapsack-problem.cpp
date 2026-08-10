class Solution {
  public:
    
    int helper(vector<int> &val, vector<int> &wt, int W, int n,vector<vector<int>> &dp)
    {   
        if(n == 0 || W == 0)
            return 0;
        
        if(dp[n-1][W-1] != -1)
            return dp[n-1][W-1];
        
        
        if(wt[n-1] <= W)
        {
            int inc = val[n-1] + helper(val, wt, W - wt[n-1], n-1, dp);
            int exc = helper(val, wt, W, n-1, dp);
            return dp[n-1][W-1] = max(inc, exc);  
        }
        else
            return dp[n-1][W-1] = helper(val, wt, W, n-1, dp);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        
        int n = val.size();
        
        vector<vector<int>> dp(n+1, vector<int> (W+1, -1));
        
       return helper(val, wt, W, n, dp);
        
    }
};