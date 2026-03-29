class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map <int, int> m;

        int n = s.length();

        for(int i = 0; i<n; i++)
        {   
            m[s[i]]++;
        }

        int idx = -1;
        for(int i = 0; i<n; i++)
        {
            if(m[s[i]] == 1)
            {   
                idx = i;
                break;
            }
        }

        return idx;
    }
};