class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> dq;
        vector<long long> prefix(n,0);
        int res = INT_MAX;
        int j = 0;
        while( j < n)
        {
            if(j == 0)
                prefix[j] = nums[j];
            else
                prefix[j] = prefix[j-1] + nums[j];
            

            if(prefix[j] >= k)
            {
                res = min(res, j+1);
            }

            while(!dq.empty() && prefix[j] <= prefix[dq.back()])
                dq.pop_back();
            
            while(!dq.empty() && prefix[j] - prefix[dq.front()] >= k)
            {
                res = min(res, j - dq.front());
                dq.pop_front();
            }

            dq.push_back(j);

            j++;
            
        }

        if(res > n)
            return -1;
        return res;
        
    }
};