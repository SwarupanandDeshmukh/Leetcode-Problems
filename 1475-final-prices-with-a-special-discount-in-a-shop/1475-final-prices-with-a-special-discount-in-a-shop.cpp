class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> res(n);
        stack<int> s;

        for(int i = 0; i<n; i++)
        {
            res[i] = prices[i];
        }

        for(int i = 0; i<n; i++)
        {
            while(!s.empty() && prices[s.top()] >= prices[i])
            {
                int dis = prices[s.top()] - prices[i];
                res[s.top()] = dis;
                s.pop();
            }
            
            s.push(i);
        }

        return res;
    }
};