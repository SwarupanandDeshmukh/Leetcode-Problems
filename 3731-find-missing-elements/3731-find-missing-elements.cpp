class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
    
       unordered_set<int> s;
       int maxi = INT_MIN;
       int mini = INT_MAX;
       int n = nums.size();
       for(int i = 0; i<n; i++)
       {    
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
            s.insert(nums[i]);
       }

        vector<int> res;
       for(int i = mini; i<=maxi; i++)
       {
            if(s.contains(i) == false)
                res.push_back(i);
       }

        return res;




        
    }
};