class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m1;
        int n = s.length();
        int m = t.length();
        int i = 0, j= 0;
        while( i < n && j < m)
        {   
            if(m1.find(s[i]) == m1.end())
            {
                for(const auto&p : m1)
                {
                    if(p.second == t[j])
                        return false;
                }
                m1.insert({s[i], t[j]});
            }
            else
            {
                if(m1[s[i]] != t[j])
                    return false;
            }
            i++;
            j++;
        }

        return true;
    }
};