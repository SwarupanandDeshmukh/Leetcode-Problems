class NumArray {
public:
    vector<int> v;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i= 0; i<n; i++)
        {
            sum = sum + nums[i];
            v.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0)
        {
            return v[right];
        }
        int s = v[right] - v[left - 1];
        return s;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */