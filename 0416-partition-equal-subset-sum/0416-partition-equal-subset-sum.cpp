class Solution {
public:

    bool helper(int i, vector<int>& nums, int totalSum, vector<vector<int>> &dp)
    {
        if(totalSum == 0)
            return true;
        
        if(i == 0)
            return (nums[i] == totalSum);
        
        if(dp[i][totalSum] != -1)
            return dp[i][totalSum];

        bool notpick = helper(i-1, nums, totalSum, dp);
        bool pick = false;
        if(nums[i] <= totalSum)
            pick = helper(i-1, nums, totalSum - nums[i], dp);
        
        return dp[i][totalSum] = pick || notpick;
    }

    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int totalSum = 0;
        for(int i = 0; i<n; i++)
        {
            totalSum += nums[i];
        }

        if(totalSum % 2 != 0)
            return false;
        
        totalSum = totalSum/2;
        vector<vector<int>> dp(n, vector<int>(totalSum+1, -1));

        return helper(n-1, nums, totalSum, dp);
    }
};