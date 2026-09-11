class Solution {
  public:
    
    int helper(int i, vector<int>& arr, int target, vector<vector<int>> &dp)
    {
        
        
        
        if(i == 0)
        {
            if(target == 0 && arr[0] == 0)
                return 2;
            
            if(target == 0 || arr[0] == target)
                return 1;
            
            return 0;
        }
        
        if(dp[i][target] != -1)
            return dp[i][target];
        
        int notpick = helper(i-1, arr, target, dp);
        int pick = 0;
        if(arr[i] <= target)
            pick = helper(i-1, arr, target - arr[i], dp);
        
        return dp[i][target] = notpick + pick;
    }
    
    int perfectSum(vector<int>& arr, int target) {
        // code here
        
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        
        int res = helper(n-1, arr, target, dp);
        
        return res;
           
    }
};