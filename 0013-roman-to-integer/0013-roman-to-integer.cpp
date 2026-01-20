class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        unordered_map<char,int> m = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        int sum = 0;
       int  i =0;
       while(i<n)
       {
            if(m[s[i]] < m[s[i+1]])
            {
                sum = sum + (m[s[i+1]] - m[s[i]]);
                i = i+2;
            }
            else
            {
                sum = sum + m[s[i]];
                i++;
            }
       }
        return sum;
    }
};