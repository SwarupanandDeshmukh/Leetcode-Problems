class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int l =0;
        int r = nums.size()-1;
        vector<int> res(nums.size()); 
        int respos = nums.size()-1;
        while(l<=r)
        {
            int leftsq = nums[l] * nums[l];
            int rightsq = nums[r] * nums[r];
            
            if(leftsq <= rightsq)
            {
                res[respos] = rightsq;
                r--;
            }
            else
            {
                res[respos] = leftsq;
                l++;
            }
            respos--;
        }
        return res;

    }
};