class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        int n = s.size();
        vector<int> freq(26, 0);

        int l = 0;
        int r = 0; 

        int ans = 0;
        while(r < n)
        {
            int idx = s[r] - 'a';
            freq[idx]++;

            while(freq[idx] > 2)
            {
                int i = s[l] - 'a';
                freq[i]--;
                l++;
            }

            ans = max(ans, r-l+1);
           
            r++;
            
        }

        return ans;
    }
};