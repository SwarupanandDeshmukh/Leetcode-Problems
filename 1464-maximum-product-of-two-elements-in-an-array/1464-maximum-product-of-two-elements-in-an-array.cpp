class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int maxi = 0;
        int smaxi = 0;
        for(int i = 0; i <n; i++)
        {

            if(nums[i] >= maxi)
            {
                smaxi = maxi;
                maxi = nums[i];  
            }
                 
             if(nums[i] < maxi && nums[i] > smaxi)
                smaxi = nums[i];
            
        }

        cout << maxi <<" " <<smaxi;

        return (maxi-1) * (smaxi - 1);
    }
};