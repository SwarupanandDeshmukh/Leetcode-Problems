class Solution {
public:
        set<vector<int>> s;
    void helper(vector<int>& candidates, int i, int target, vector<int> &comb, vector<vector<int>> &ans)
    {
        if(target == 0)
        {
            if(s.find(comb) == s.end())
            {
                s.insert(comb);
                ans.push_back(comb);
            }
              return;
        }

        if(target< 0 || i == candidates.size())
        {
            return;
        }
        comb.push_back(candidates[i]);

        helper(candidates, i, target - candidates[i], comb, ans);

        comb.pop_back();

        helper(candidates, i+1, target, comb, ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;

        helper(candidates, 0, target, comb, ans);

        return ans;
    }
};