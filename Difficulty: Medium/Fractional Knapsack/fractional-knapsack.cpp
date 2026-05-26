class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        
       vector<pair<double, int>> v;
        
        for(int i = 0; i<n; i++)
        {
            double ratio = (double)val[i]/ (double)wt[i];
            v.push_back({ratio, i});
        }
        
        sort(v.begin(), v.end(), greater<pair<double, int>>());
        
        double totalValue = 0;
        for(auto& p : v)
        {
            if(capacity > 0)
            {
                if(wt[p.second] <= capacity)
                {
                    totalValue += val[p.second];
                    capacity -= wt[p.second];
                }
                else
                {
                    totalValue += (capacity * p.first);
                    capacity = 0;
                }
            }
            else
                break;
        }
        
        return totalValue;
    }
};
