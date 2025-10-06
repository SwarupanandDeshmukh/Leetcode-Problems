class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

     int unq = 0;
     for(int i = 1; i< nums.size();i++)
     {
        if(nums[i] != nums[unq])
        {
            unq++;
            nums[unq] = nums[i];
        }
     }   
     return unq+1;
    }
};