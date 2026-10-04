class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        int n = heights.size();

        vector<int> expected;
        expected = heights;

        sort(expected.begin(), expected.end());

        for(int i : expected)   
            cout << i << " ";
        
        int cnt = 0;
        for(int i = 0; i<n; i++)
        {
            if(expected[i] != heights[i])
                cnt++;
        }

        return cnt;
    }
};