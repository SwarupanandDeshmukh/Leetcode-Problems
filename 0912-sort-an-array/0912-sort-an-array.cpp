class Solution {
public:

    void mergesort(vector<int>& nums, int n, int s, int mid, int e)
    {
        int i = s;
        vector<int> res;
        int j = mid+1;

        while(i<=mid && j<=e)
        {
            if(nums[i] <= nums[j])
            {
                res.push_back(nums[i]);
                i++;
            }
            else
            {
                res.push_back(nums[j]);
                j++;
            }
        }


        while(i<=mid)
        {
             res.push_back(nums[i]);
                i++;
        }

        while(j<=e)
        {
            res.push_back(nums[j]);
            j++;
        }


        for(int i = 0; i<res.size(); i++)
        {
            nums[i+s] = res[i];
        }
    }


    void merge(vector<int>& nums, int n, int s, int e)
    {
        if(s<e)
        {
            int mid = s + (e - s)/2;
            merge(nums,n,s, mid);
            merge(nums,n,mid+1,e);

            mergesort(nums, n, s, mid, e);

        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n-1;

        merge(nums, n, s, e);

        return nums;
    }
};