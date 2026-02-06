class Solution {
public:

    void helper(int idx, int n, int k, vector<int> &comb, vector<vector<int>> &res)
    {
        if(comb.size() == k)
        {
            res.push_back(comb);
            return;
        }

        for (int i = idx; i <= n; i++) {
            comb.push_back(i);
            helper(i + 1, n, k, comb, res);
            comb.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        vector<vector<int>> res;
        int idx = 1;

        helper(idx, n, k, comb, res);

        return res;
    }
};