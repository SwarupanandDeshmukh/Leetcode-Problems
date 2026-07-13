class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n = arr.size();
        if(n == 0)
            return {};
        

        vector<int> newarr = arr;
        sort(arr.begin(), arr.end());
        int maxi = arr[0];
        vector<int> res;
        unordered_map<int, int> m;
        int r = 1;
        m[arr[0]] = 1;
        int maxidx = 0;
        for(int i = 1; i< n; i++)
        {
            if(arr[i] > maxi)
            {
                maxidx = i;
                maxi = arr[i];
                r++;
                m[arr[i]] = r;
            }
        }

        for(int i = 0; i<n; i++)
        {
           res.push_back(m[newarr[i]]);
        }

        return res;
    }
};