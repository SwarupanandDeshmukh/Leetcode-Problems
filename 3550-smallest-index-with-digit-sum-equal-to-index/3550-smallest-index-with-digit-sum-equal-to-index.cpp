class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        
        int n = nums.size();

        for(int i = 0; i<n; i++)
        {
            if(nums[i] < 10)
            {
                if(i == nums[i])
                    return i;
            }   
            if(nums[i] >= 10)
            {
                int sum = 0;
                int val = nums[i];
                while(val > 0)
                {
                    int rem = val % 10;
                    sum += rem;
                    val = val / 10;
                }

                if(sum == i)
                    return i;
            }
        }

        return -1;
    }
};