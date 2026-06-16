class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        
        vector<int> res;

        for(const auto row: matrix)
        {
            int cnt = 0;

            for(int i = 0; i<row.size(); i++)
            {
                if(row[i] == 1)
                    cnt++;
            }
            res.push_back(cnt);
        }

        return res;
    }
};