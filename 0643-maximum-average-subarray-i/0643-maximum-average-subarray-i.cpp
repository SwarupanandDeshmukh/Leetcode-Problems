class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        double maxAvg = 0.0;
        for(int i = 0; i<k; i++)
        {
            sum = sum + nums[i];
        }
        maxAvg = (double)sum/k;

        for(int i = k; i<n; i++)
        {
            sum = sum - nums[i-k] + nums[i];
            double aver = (double)sum /k;
            if(aver > maxAvg)
                maxAvg = aver;
        }

        return maxAvg;

    }
};