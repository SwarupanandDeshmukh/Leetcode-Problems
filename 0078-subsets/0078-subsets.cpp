class Solution {
public:
    set<vector<int>> s;

    void helper(vector<int>& nums, int n, int i, vector<int> sub, vector<vector<int>> &ans)
    {
        if(i == n)
        {
            if(s.find(sub) == s.end())
            {
                s.insert(sub);
                ans.push_back(sub);
            }

            return;
        }

        sub.push_back(nums[i]);
        helper(nums,n ,i+1 ,sub, ans);
        sub.pop_back();
        helper(nums,n ,i+1 ,sub, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        vector<int> sub;
        vector<vector<int>> ans;

        helper(nums, n, 0, sub, ans);

        return ans;
    }
};