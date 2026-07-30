class Solution {
public:
    char findTheDifference(string s, string t) {
        
        unordered_map<char, int> m;

        for(char c: s)
        {
            m[c]++;
        }

        for(char c: t)
        {
            auto it = m.find(c);
            if(it != m.end())
            {
                if(m[it->first] == 0)
                    return c;
                
                m[it->first]--;

            }
            else
                return c;
        }

        return ' ';

        

        
    }
};