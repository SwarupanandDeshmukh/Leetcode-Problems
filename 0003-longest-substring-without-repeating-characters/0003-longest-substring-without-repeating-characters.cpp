class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();

        unordered_map<char, bool> m;

        int l = 0;
        int r = 0;
        int cnt = 0;

        if(n == 1)
            return 1;


        while(l <= r)
        {
            while(r < n && !m.contains(s[r]))
            {
                m[s[r]] = true;
                r++;
            }

            cnt = max(cnt, r-l);
            
            if(r == n)
                break;
            
            if(m.contains(s[r]))
                 m.clear();
            

            l++;
            r = l;
        }

        return cnt;


    }
};