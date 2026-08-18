class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        
        int n = nums.size();
        int l = 0, r = 0;
        unordered_map<int, int> m;
        unordered_set<int> s;

        if(n == 1)
            return nums[0];

        while(r < (n-k)+1)
        {
            int cnt = 0;
            unordered_set<int> s;

            while(cnt < k)
            {
               s.insert(nums[r]);

                cnt++;
                r++;
            }

            for(int i : s)
                m[i]++;
            
            l++;
            r = l;
        }

        for(auto pair: m)
        {
            cout<< pair.first <<" " << pair.second << endl;
        }

        int maxi = -1;
        for(auto pair: m)
        {
            if(pair.second == 1)
                maxi = max(maxi, pair.first);
        }

        return maxi;
    }
};