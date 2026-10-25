class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        int l = 0;
        unordered_map<char, int> m;
        int maxi  = 0;

        for(int r = 0; r <n; r++)
        {
            if(m.contains(s[r]) && m[s[r]] >= l)
            {
                l = m[s[r]] + 1;
            }
            m[s[r]] = r;
            maxi = max(maxi, r - l + 1);
        }

        return maxi;

    }
};