class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();

        int maxi = INT_MIN;
        for(int i = 0; i<n; i++)
        {
            maxi = max(maxi, nums[i]);
        }

        vector<int> freq(maxi + 1, 0);

        for(int i= 0; i<n; i++)
        {
            freq[nums[i]]++; 
        }

        int idx = 0;
        for(int i = 0; i <= maxi; i++)
        {  
            if(freq[i] != 0)
            {
                while(freq[i] > 0)
                {
                    nums[idx] = i;
                    idx++;
                    freq[i]--;
                }
            }
        }

    }
};