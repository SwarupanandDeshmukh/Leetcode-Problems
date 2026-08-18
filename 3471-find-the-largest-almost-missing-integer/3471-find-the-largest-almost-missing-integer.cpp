class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> m;

        for(int i : nums)
        {
            m[i]++;
        }

        if(k == n)
        {
            int maxi = 0;
            for(int i = 0; i<n; i++)
            {
                maxi = max(maxi, nums[i]);
            }

            return maxi;
        }

        if(k == 1)
        {   
            int maxi = -1;
            for(auto pair: m)
            {
                if(pair.second == 1)
                    maxi = max(maxi, pair.first);
            }

            return maxi;
        }

            if(m[nums[0]] == 1 && m[nums[n-1]] == 1)
                return max(nums[0], nums[n-1]);

           
            if(m[nums[0]] == 1 && m[nums[n-1]] > 1)
                return nums[0];
            
            if(m[nums[0]] > 1 && m[nums[n-1]] == 1)
                return nums[n-1];
            
        return -1;

    }
};