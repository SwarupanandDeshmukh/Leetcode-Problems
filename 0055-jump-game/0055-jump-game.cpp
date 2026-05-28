class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int maxi = 0;
        int n = nums.size();

        if(n == 1)
            return true;
        
        for(int i = 0; i<n-1; i++)
        {   
            if(i > maxi)
                break;
            maxi = max(maxi, i + nums[i]);

            if(maxi >= n-1)
                return true;
        }

        return false;
    }
};