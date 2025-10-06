class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l =0;
        int n = numbers.size();
        int r = n-1;
        while(l<r)
        {   
            int sum =0;
            sum = numbers[l] + numbers[r];
            if(target == sum)
                return {l+1,r+1};
            else if (sum < target)
                l++;
            else
                r--; 
        }
        return {0};
       
    }
};