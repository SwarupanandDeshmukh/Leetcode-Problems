class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        
        int sublen = part.length();

        while(true)
        {
            int cnt = 0;
            int n = s.length();
            int j = 0;
            for(int i = 0; i<n; i++)
            {
                string word = "";
                int idx = i;
                int winIdx = 0;

                while(winIdx < sublen && idx < n)
                {
                    word = word + s[idx];
                    winIdx++;
                    idx++;
                }

                if(word == part)
                {
                    s.erase(j,part.length());
                    n = s.length();
                    cnt++;
                    break;
                }
                j = j+1;
            }

            if(cnt == 0)
            {
                break;
            }
        }

        return s;
    }
};