class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
        {
            return a[0] < b[0];
        });


        int cur_start = intervals[0][0];
        int cur_end = intervals[0][1];

        int cnt = 0;
        for(int i = 1; i<n; i++)
        {
            if(intervals[i][0] < cur_end)
            {
                cur_end = min(cur_end, intervals[i][1]);
                cnt++;
            }
            else
            {
                cur_start = intervals[i][0];
                cur_end = intervals[i][1];
            }
        }

        return cnt;
    }
};