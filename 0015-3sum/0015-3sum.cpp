class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int n = nums.size();
        set<vector<int>> s;

        for(int i = 0; i<n-2;i++)
        {
            int l = i+1;
            int r = n -1;

            while(l<r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0)
                {
                    s.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                else if(sum < 0)
                    l++;
                else
                    r--;
            }
        }

        return vector<vector<int>>(s.begin(),s.end());
    }
};