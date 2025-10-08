class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());
         int n = nums.size();
        int min_diff = INT_MAX;
        int resSum = 0;
        for(int i =0; i< n-2;i++)
        {
            int l = i+1;
            int r = n -1;

            while(l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                int diff = target - sum;

                if(abs(diff) < abs(min_diff))
                {
                    min_diff = diff;
                    resSum = sum;
                }
                if(sum < target)
                    l++;
                else
                    r--;
            }
        }

        return resSum;

    }
};