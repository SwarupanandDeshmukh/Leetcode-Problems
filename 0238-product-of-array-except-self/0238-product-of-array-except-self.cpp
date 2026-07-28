class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();

        int prod = 1;
        int cnt = 0;
        for(int i = 0; i<n; i++)
        {   
            if(nums[i] != 0)
                prod *= nums[i];
            else
            {
                cnt++;
            }
        }

        if(prod == 1 && cnt == n)
            prod = 0;
        
        vector<int> res(n);
        
        if(cnt > 1)
        {
            return vector<int> (n, 0);
        }

        for(int i = 0; i<n; i++)
        {

            if(nums[i] == 0 )
            {
                res[i] = prod;
                continue;
            }

            if(cnt > 0)
                res[i] = 0;
            else
                res[i] = prod / nums[i];

        } 

        return res;
    }
};