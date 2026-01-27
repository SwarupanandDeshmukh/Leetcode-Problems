class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        int len = 0;
        vector<int> lps(n,0);
        lps[0] = len;
        int i =1;
        while(i < n)
        {
            if(s[i] == s[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if(len !=0)
                    len = lps[len -1];
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        if(len == 0)
        {
            return "";
        }
        return s.substr(0,len);
    }
};