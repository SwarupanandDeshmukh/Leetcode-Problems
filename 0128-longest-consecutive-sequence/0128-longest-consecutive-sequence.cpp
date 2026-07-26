class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        map<int, int> m;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            m[nums[i]] = 0;
        }
    

        vector<int> res;

        int cnt = 0;
        int diff = 0;
        int maxi = 0;
        for(const auto pair : m)
        {   
            int val = abs(pair.first - diff);

            if(val != 1)
            {
                cnt = 1;
                maxi = max(cnt, maxi);
            }
                
            else if(val == 1)
            {
                cnt++;
                maxi = max(cnt, maxi);
            }

             diff = pair.first;
        }

        return maxi;
    }
};