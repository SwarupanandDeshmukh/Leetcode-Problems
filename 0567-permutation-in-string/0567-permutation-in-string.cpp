class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> m1;
        int n = s1.length();
        for(int i = 0; i<n; i++)
        {
            m1[s1[i]]++;
        }

        int windowSize = n;
        for(int i = 0; i<s2.length(); i++)
        {
            int windowIdx = 0, idx = i;
            unordered_map<char,int> m2;
            
            while(windowIdx < windowSize && idx < s2.length())
            {
                m2[s2[idx]]++;
                windowIdx++;
                idx++;
            }

            if(m1 == m2)
                return true;
        }

        return false;
    }
};