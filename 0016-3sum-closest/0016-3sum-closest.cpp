class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        int res = nums[0] + nums[1] + nums[2];
        int mini = INT_MAX;
        sort(nums.begin(), nums.end());

        for(int i = 0; i<n-2; i++)
        {
            int left = i + 1;
            int right = n - 1;

            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if(sum == target)
                    return sum;
                else if(sum > target)
                    right--;
                else
                    left++;

                if(abs(sum - target) < mini)
                {
                    res = sum;
                    mini = abs(sum - target);
                }
            }
        }

        return res;
    }
};