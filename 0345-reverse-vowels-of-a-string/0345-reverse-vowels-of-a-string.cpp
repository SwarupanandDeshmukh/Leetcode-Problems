class Solution {
public:
    string reverseVowels(string s) {
        
        int n = s.size();

        unordered_set<char> vowel;
        vowel.insert({'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'});

        int l = 0;
        int r = 0;
        for(int i = 0; i<n; i++)
        {
            if(vowel.contains(s[i]))
            {
                l = i;
                break;
            }
        }

        for(int i = n-1; i>=0; i--)
        {
            if(vowel.contains(s[i]))
            {
                r = i;
                break;
            }
        }


        while(l < r)
        {
            if(vowel.contains(s[l]) && vowel.contains(s[r]))
            {
                char t = s[l];
                s[l] = s[r];
                s[r] = t;

                l++;
                r--;
            }
            else if(vowel.contains(s[l]) && !vowel.contains(s[r]))
                r--;
            
             else if(vowel.contains(s[r]) && !vowel.contains(s[l]))
                l++;
            
            else
            {
                l++;
                r--;
            }
        }

        return s;




    }
};