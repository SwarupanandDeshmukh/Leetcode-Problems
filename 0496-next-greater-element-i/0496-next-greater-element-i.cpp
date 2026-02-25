class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums2.size();
        unordered_map<int,int> m;
        stack<int> s;

        for(int i = 0; i<n; i++)
        {
            m[nums2[i]] = -1;
        }

        
        for(int i = 0; i<n; i++)
        {
           
            while(!s.empty() && s.top() < nums2[i])
            {
                m[s.top()] = nums2[i]; 
                s.pop();
            }
             s.push(nums2[i]);

        }

        vector<int> res(nums1.size());
        for(int i = 0; i<nums1.size(); i++)
        {
            res[i] = m[nums1[i]];
        }

        return res;
    }
};