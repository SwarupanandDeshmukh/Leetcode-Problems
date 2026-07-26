class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> res;

        int i = 0;
        int j = 0;
        int n = nums1.size();
        int m = nums2.size();

        while(i < n && j < m)
        {
            if(nums1[i] <= nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
            }
            else if(nums2[j] < nums1[i])
            {
                res.push_back(nums2[j]);
                j++;
            }
        }

        while(i < n)
        {
            res.push_back(nums1[i]);
            i++;
        }

        while(j < m)
        {
            res.push_back(nums2[j]);
            j++;
        }

        int s = res.size();
        cout<< s;

        double val;
        if(s % 2 == 0)
        {
            int i1 = s/2;
            int i2 = i1 -1;
            val = ((double)res[i1] + (double)res[i2]) / 2;
        }
        else
        {
            int idx = s /2;
            val = res[idx];
        }

        return val;

    }
};