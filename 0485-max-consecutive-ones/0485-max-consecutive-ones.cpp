class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();
        int maxC = INT_MIN;
        int c = 0;
        int f = 0;
        for(int i = 0; i<n; i++)
        {
            if(nums[i] == 1)
            {
                c++;
                maxC = max(maxC,c);
                f = 1;
            }
            else
            {
                c = 0;
            }
        }

        if(f == 0)
            return 0;

        return maxC;
    }
};