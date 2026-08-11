class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.length();

        vector<string> words;

        string word = "";
        for(int i = 0; i<n; i++)
        {
            if(s[i] != ' ')
                word += s[i];
            else
            {
                words.push_back(word);
                word = "";
            }
        }

        words.push_back(word);

        string res = "";
        for(string t: words)
        {
            reverse(t.begin(), t.end());
            res = res + t + " ";
        }
        
        res.pop_back();
        return res;

    }
};