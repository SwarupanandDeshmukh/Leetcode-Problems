class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        
        int n = arr.size();
        
        vector<vector<int>> dp(n+1, vector<int> (sum + 1, 0));
        
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=sum; j++)
            {
                if(arr[i-1] <= j)
                {
                    int take = arr[i-1] + dp[i-1][j - arr[i-1]];
                    
                    int notTake = dp[i-1][j];
                    
                    dp[i][j] = max(take, notTake);
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return (dp[n][sum] == sum); 
        
        
    }
};