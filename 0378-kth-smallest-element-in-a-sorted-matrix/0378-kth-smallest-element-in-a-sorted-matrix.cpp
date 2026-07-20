class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int cnt = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i <n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                pq.push(matrix[i][j]);
            }

        }

        while(!pq.empty())
        {
            int val = pq.top();
            pq.pop();

            cnt++;

            if(cnt == k)
                return val;
        }

        return -1;
    }
};