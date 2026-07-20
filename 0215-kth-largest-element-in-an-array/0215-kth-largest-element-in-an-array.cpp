class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int n = nums.size();

        priority_queue<int, vector<int>> pq;

        for(int i = 0; i<n; i++)
        {
            pq.push(nums[i]);
        }

        int cnt = 0;
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