class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0]; 
        });

        int cur_start = intervals[0][0];
        int cur_end = intervals[0][1];
        int n = intervals.size();

        vector<vector<int>> res;
        for(int i = 1; i<n; i++)
        {
            if(intervals[i][0] <= cur_end)
            {
                cur_end = max(cur_end, intervals[i][1]);
            }
            else
            {
                res.push_back({cur_start, cur_end});
                cur_start = intervals[i][0];
                cur_end = intervals[i][1];
            }
        }
        res.push_back({cur_start, cur_end});

        return res;
    }
};