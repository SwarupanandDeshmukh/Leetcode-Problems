class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l =0;
        int r = 0;
        int n = nums.size();
        int sum = 0;
        int minLen = INT_MAX;
        while(r < n )
        {
            sum = sum + nums[r];
            while(sum >= target)
            {
                minLen = min(minLen, r-l+1);
                sum = sum - nums[l];
                l++;
            }
           r++;
        }
        if(minLen > nums.size())
            return 0;
        return minLen;
    }
};