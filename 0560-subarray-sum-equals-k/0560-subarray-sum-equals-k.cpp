class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int> m;
        vector<int> v(n);
        v[0] = nums[0];
        for(int i =1;i<n; i++)
        {
            v[i] = v[i-1] + nums[i];
        }

        for(int j = 0; j<n; j++)
        {
            if(v[j] == k)
                ans++;
            int ps = v[j] - k;
            if(m.contains(ps))
            {
                ans = ans + m[ps];
            }
            m[v[j]]++;  
        }

        return ans;
        
    }
};