class Solution {
public:

    long long gcdSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> tillmax(n, 0);

        int maxi = 0;
        for(int i = 0; i<n; i++)
        {
            maxi = max(maxi, nums[i]);
            tillmax[i] = maxi;
        }

        vector<int> prefixGCD(n, 0);
        int i= 0;
        while(i < n)
        {
            int larger = max(nums[i], tillmax[i]);
            int smaller = min(nums[i], tillmax[i]);
            int rem = larger % smaller;

            while(rem > 0)
            {
                larger = smaller;
                smaller = rem;
                rem = larger % smaller;
            }

            prefixGCD[i] = smaller;
            i++;
        }

        sort(prefixGCD.begin(), prefixGCD.end());

        int l = 0;
        int h = n-1;

        long long sum = 0;
        while(l<h)
        {
            int larger = max(prefixGCD[l], prefixGCD[h]);
            int smaller = min(prefixGCD[l], prefixGCD[h]);
            int rem = larger % smaller;

            while(rem > 0)
            {
                larger = smaller;
                smaller = rem;
                rem = larger % smaller;
            }

            sum += smaller;
            l++;
            h--;
        }

        return sum;



    }
};