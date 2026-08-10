class Solution {
public:
    string trimTrailingVowels(string s) {
        
        int n = s.length();
        string res;
        int idx;
        for(int i = n-1; i>=0; i--)
        {
            if(s[i] == 'a' || s[i] == 'o' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u')
                continue;
            else
            {
                idx = i;
                break;
            }
        }

        return s.substr(0, idx+1);
    }
};