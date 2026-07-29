class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> pre(n);
        
        pre[0] = nums[0];
        for(int i = 1; i<n; i++)
        {
            pre[i] = pre[i-1] + nums[i];
        }

        int left = 0;
        int right = 0;
        for(int i = 0; i<n; i++)
        {
            if(i == 0)
            {
                left = 0;
                right = pre[n-1] - pre[i];
            }
            else if(i == n-1)
            {
                left = pre[i-1];
                right = 0;
            }
            else
            {
                left = pre[i-1];
                right = right = pre[n-1] - pre[i];
            }

            if(left == right)
                return i;

        }

        return -1;
    }
};