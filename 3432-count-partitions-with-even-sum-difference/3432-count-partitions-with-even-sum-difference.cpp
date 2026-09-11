class Solution {
public:
    int countPartitions(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> prefix(n, 0);

        prefix[0] = nums[0];
        for(int i = 1; i<n; i++)
        {   
            prefix[i] = prefix[i-1] + nums[i];
        }

       int cnt = 0;
       for(int i = 0; i<n-1; i++)
       {
            int diff = prefix[i] - (prefix[i] - prefix[n-1]);
            if(diff % 2 == 0)
                cnt++;

       }

       return cnt;

    }
};