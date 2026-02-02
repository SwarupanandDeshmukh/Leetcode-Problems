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
        helper(candidates, i+1, target - candidates[i] , comb, ans);
        comb.pop_back();

        while(i+1 < candidates.size() && candidates[i] == candidates[i+1])
            i++;
        
        helper(candidates, i+1, target, comb,ans);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;

        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target, comb, ans);

        return ans;
    }
};