class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> rowMin;
        vector<int> colMax;

        for(int i = 0; i<m; i++)
        {
            int mini = INT_MAX;
            for(int j = 0; j<n; j++)
            {
                mini = min(matrix[i][j], mini);
            }
            rowMin.push_back(mini);
        }

        for(int i = 0; i<n; i++)
        {
            int maxi = INT_MIN;
            for(int j = 0; j<m; j++)
            {
                maxi = max(matrix[j][i], maxi);
            }

            colMax.push_back(maxi);
        }

        vector<int> res;
        for(int i = 0; i<rowMin.size(); i++)
        {
            for(int j = 0; j<colMax.size(); j++)
            {
                if(rowMin[i] == colMax[j])
                {
                    res.push_back(rowMin[i]);
                    break;
                }
            }
        }

        return res;
    }
};