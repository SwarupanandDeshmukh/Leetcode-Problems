class Solution {
public:
    
    int helper(vector<int> &nums, int s, int e)
    {
        int n = (e - s) + 1;

        if(n == 1)
            return nums[s];
        
        if(n == 2)
            return max(nums[s], nums[s+1]);
        
        vector<int> dp(n);

        dp[0] = nums[s];
        dp[1] = max(nums[s], nums[s+1]);

        for(int i = 2; i<n; i++)
        {
            int pick = nums[s+i] + dp[i-2];
        
            int notpick = 0 + dp[i-1];

            dp[i] = max(pick, notpick);
        }

        int maxi = 0;
        for(int i = 0; i<n; i++)
        {   
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        int first = helper(nums, 0, n-2);
        int last = helper(nums, 1, n-1);

        return max(first, last);

    }
};