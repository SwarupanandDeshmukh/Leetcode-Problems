class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;

        for(int i = n-2; i>=0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                idx = i;
                break;
            }
        }

        if(idx == -1)
        {
            int l = 0;
            int r = n-1;
            while(l<r)
            {
                int t = nums[l];
                nums[l] = nums[r];
                nums[r] = t;
                l++;
                r--;
            }

            return;
        }

        for(int i = n-1; i> idx; i--)
        {
            if(nums[i] > nums[idx])
            {
                int t = nums[i];
                nums[i] = nums[idx];
                nums[idx] = t;
                break;
            }
        }

            int l = idx + 1;
            int r = n-1;
            while(l<r)
            {
                int t = nums[l];
                nums[l] = nums[r];
                nums[r] = t;
                l++;
                r--;
            }

    }
};