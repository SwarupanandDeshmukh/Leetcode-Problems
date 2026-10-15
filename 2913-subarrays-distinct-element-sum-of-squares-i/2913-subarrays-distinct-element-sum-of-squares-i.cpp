class Solution {
public:
    int sumCounts(vector<int>& nums) {
        
        int n = nums.size();

        set<int> inner;

        vector<set<int>> res;

        for(int i = 0; i<n; i++)
        {
            for(int j = i; j<n; j++)
            {
                for(int k = i; k<=j; k++)
                {
                    inner.insert(nums[k]);
                }
                res.push_back(inner);
                inner.clear();
            }
        }


    
        int sum = 0;
        for(auto s : res)
        {
            int setSize = s.size();
            sum += setSize * setSize;
        }

        return sum;
    }

};