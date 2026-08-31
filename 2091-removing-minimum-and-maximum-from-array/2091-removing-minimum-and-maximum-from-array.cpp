class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 1)
            return 1;
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int minidx = 0, maxidx = 0;
        for(int i = 0; i<n; i++)
        {
           if(nums[i] < mini)
            {
                mini = nums[i];
                minidx = i;
            }

            if(nums[i] > maxi)
            {
                maxi = nums[i];
                maxidx = i;
            }
        }


        int left = max(minidx, maxidx) + 1;
        int right = n - min(minidx, maxidx);
        
        int both1 = (minidx + 1) + (n - maxidx);
        int both2 = (maxidx + 1) + (n - minidx);

        cout << left <<" " << right<< " " <<both1 << " " << both2 << endl;

        return min({left, right, both1, both2});    
        
        
    }
};