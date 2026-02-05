class Solution {
public:

    void helper(vector<int>& nums, int n,vector<int> &perm, vector<bool> &used, vector<vector<int>> &res)
    {
        if(perm.size() == n)
        {
            res.push_back(perm);
            return;
        }

        for(int i = 0; i<n; i++)
        {
            if(used[i] == true)
                continue;
            
            used[i] = true;
            perm.push_back(nums[i]);

            helper(nums, n, perm, used, res);

            perm.pop_back();
            used[i] = false;
        }  
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        vector<int> perm;
        vector<vector<int>> res;

        vector<bool> used(n, false);

        helper(nums, n,perm, used,res);
        return res;
    }
};