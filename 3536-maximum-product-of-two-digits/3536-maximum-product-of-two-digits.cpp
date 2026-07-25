class Solution {
public:
    int maxProduct(int n) {
        
        int rem = 0;
        vector<int> res;
        while(n > 0)
        {
            rem = n % 10;
            res.push_back(rem);
            n = n / 10;
        }

        sort(res.begin(), res.end());
        
        int s = res.size();
        return res[s-1] * res[s-2];

        

    }
};