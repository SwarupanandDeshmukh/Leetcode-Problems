class Solution {
public:
    string smallestPalindrome(string s) {
        
        vector<int> freq(26, 0);
        int n = s.size();

        for(int i = 0; i<n; i++)
        {
            int idx = s[i] - 'a';
            freq[idx]++;
        }
    

        string left = "";
        string right = "";
        string middle = "";

        for(int i = 0; i<26; i++)
        {   
            if(freq[i] == 0)
                continue;
            
            char ch = (char)(97 + i);

            if(freq[i] % 2 != 0)
            {
                middle += ch;
            }
    
            int cnt = freq[i] / 2;
            left.append(cnt, ch);
        }

        right = left;
        reverse(right.begin(), right.end());

        string res; 
        res = left + middle + right;

        return res;




    }
};