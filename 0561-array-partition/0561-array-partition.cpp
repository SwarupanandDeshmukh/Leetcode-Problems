class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int sum = 0;
        for(int i = 0; i<n; i = i+2)
        {
            sum = sum + min(nums[i], nums[i+1]);
        }

        return sum;
    }

};