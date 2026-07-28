class Solution {
public:
    string smallestPalindrome(string s) {
        
        map<char, int> m;
        int n = s.size();

        for(int i = 0; i<n; i++)
        {
            m[s[i]]++;
        }

        string left = "";
        string right = "";
        string middle = "";

        for(auto pair: m)
        {
            if(pair.second % 2 != 0)
            {
                middle += pair.first;
            }
    
            int cnt = pair.second / 2;
            left.append(cnt, pair.first);
        }

        right = left;
        reverse(right.begin(), right.end());

        string res; 
        res = left + middle + right;

        return res;




    }
};