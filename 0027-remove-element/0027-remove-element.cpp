class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size();
        for(int i = 0; i<n; i++)
        {
            if(nums[i] == val)
                nums[i] = 1000;
        }

        int cnt = 0;
        for(int i = 0; i<n; i++)
        {
            if(nums[i] != 1000)
                cnt++;
        }

        sort(nums.begin(), nums.end());

        return cnt;
    }
};