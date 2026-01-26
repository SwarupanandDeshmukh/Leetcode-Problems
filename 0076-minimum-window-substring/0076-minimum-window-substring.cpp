class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        int sidx = -1;
        int minLength = INT_MAX;

        if(m > n)
            return "";


        vector<int> hashmap(256,0);
        int cnt = 0;
        for(int i = 0; i<m; i++)
        {
            hashmap[t[i]]++;
        }
        
        int l =0,r = 0;
        while(r < s.length())
        {
            if(hashmap[s[r]] > 0)
                cnt = cnt + 1;
            hashmap[s[r]] --;

            while(cnt == m)
            {
                if(r-l+1 < minLength)
                {
                    minLength = r-l+1;
                    sidx = l;
                }

                hashmap[s[l]]++;
                if(hashmap[s[l]] > 0)
                    cnt = cnt -1;
                
                l++;

            }
            r++;
        }

        if(sidx == -1)
            return "";
        else
            return s.substr(sidx, minLength);

    }
};