class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int n = nums.size();
        int l = 0;
        int sum = 0;
        double maxi = INT_MIN;

        for(int r = 0; r < n; r++)
        {
            sum += nums[r];

            if(r -l + 1 == k)
            {
                double avg = (double) sum / (r-l+1);
                maxi = max(maxi, avg);
                sum -= nums[l];
                l++;
            }
        }

        return maxi;
    }
};