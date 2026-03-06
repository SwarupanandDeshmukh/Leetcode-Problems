class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res(n);
        stack<int> s;

        // think of it like traversing the array twice.

        for(int i = 2*n - 1; i>=0; i--)
        {
            while(!s.empty() && nums[s.top()] <= nums[i%n])
            {
                s.pop();
            }

            res[i%n] = s.empty() ? -1 : nums[s.top()];

            s.push(i%n);
            

        }

        return res;

    }
};