class Solution {
public:
    int findGCD(vector<int>& nums) {
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n = nums.size();

        for(int i = 0; i<n; i++)
        {
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }

        int rem = maxi % mini;

        while(rem > 0)
        {
            maxi = mini;
            mini = rem;
            rem = maxi % mini;
        }

        return mini;
    }
};