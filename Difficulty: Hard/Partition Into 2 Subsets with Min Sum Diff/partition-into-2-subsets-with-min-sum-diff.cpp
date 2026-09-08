class Solution {
  public:
  
    bool helper(int i, int sum, vector<int>& arr, vector<vector<int>> &dp)
    {
        if(sum == 0)
            return true;
        
        if(i == 0)
            return arr[0] == sum;
        
        if(dp[i][sum] != -1)
            return dp[i][sum];
            
        bool notpick = helper(i-1, sum, arr, dp);
        bool pick = false;
        if(arr[i] <= sum)
            pick = helper(i-1, sum - arr[i], arr, dp);
        
        return dp[i][sum] = pick || notpick;
       
        
    }
    
    int minDifference(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int sum = 0;
        for(int i = 0; i<n; i++)
        {
            sum += arr[i];
        }
    
        vector<vector<int>> dp(n, vector<int> (sum + 1, -1));
        
        bool res = helper(n-1,sum, arr, dp);
        vector<int> v;
    
        for(int j = 0; j<= sum; j++)
        {
            if(helper(n-1, j, arr, dp))
                    v.push_back(j);
        }
        
        int mini = INT_MAX;
        for(int i = 0; i<v.size(); i++)
        {
            int other = sum - v[i];
            mini = min(mini, abs(other - v[i]));
        }
        
        return mini;
        
        
    }
};
