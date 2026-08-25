class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        if(k == 1)
        {

        }

        int n = nums.size();
        unordered_map<int, int> divisors;
        for(int i = 0; i<n; i++)
        {
            if(nums[i] % k == 0)
            {
                int quo = nums[i] / k;
                divisors[quo] = 1;
            }
        }

        for(auto pair : divisors)
       {
            cout << pair.first << " ";
       }

        int maxi = 0;
       for(auto pair : divisors)
       {
            maxi = max(maxi, pair.first);
       }

        int val = 0;
        int flag = 0;
        for(int i = 1; i<=maxi; i++)
        {
            if(!divisors.contains(i))
            {
                flag = 1;
                val = i;
                break;
            }   
        }

        if(flag == 1)
            return val * k;

        return (maxi+1) * k;

    }
};