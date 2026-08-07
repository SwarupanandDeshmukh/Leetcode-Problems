class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 1)
        {
            return nums[0];
        }
        if(n == 2)
        {
            return max(nums[0], nums[1]);
        }

        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        int maxi = 0;
        for(int i = 2; i<n; i++)
        {
             int pick = nums[i] + dp[i-2];
            int notpick = 0 + dp[i-1];

            dp[i] = max(pick, notpick);
        }


        for(int i = 0; i<n; i++)
        {
            maxi = max(maxi, dp[i]);
        }

        return maxi;

    }
};