class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());

        // if(s == t)
        // {
        //     return true;
        // }
        // else
        // {
        //     return false;
        // }

        map<char,int> m1;
        map<char,int> m2;

        for(char ch : s)
        {
            m1[ch] = m1[ch] + 1;
        }
        
        for(char ch : t)
        {
            m2[ch]++;
        }

       return m1 == m2;
    }
};