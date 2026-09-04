class Solution {
  public:
    
    bool helper(int i, vector<int>& arr, int sum,  vector<vector<int>> &dp)
    {
        if(sum == 0)
            return true;
        
        if(i == 0)
            return (arr[0] == sum);
        
        if(dp[i][sum] != -1)
            return dp[i][sum];
        
        bool notpick = helper(i-1, arr, sum, dp);
        bool pick = false;
        
        if(sum >= arr[i])
        {
            pick = helper(i-1,arr,  sum - arr[i], dp);
        }
        
        return dp[i][sum] = pick || notpick;
        
    }
    
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        
        return helper(n-1, arr, sum, dp);
    }
};