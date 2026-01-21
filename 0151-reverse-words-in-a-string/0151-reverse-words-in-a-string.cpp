class Solution {
public:
    string reverseWords(string s) {

        string word = "";
        stringstream ss(s);
        s = "";
        while(ss >> word)
            s = s + word + " ";
        
        if(!s.empty())
            s.pop_back();
        
        reverse(s.begin(), s.end());
        string result = "";
        for(int i = 0; i<s.length(); i++)
        {
            string word = "";
            while(i<s.length() && s[i] != ' ')
            {
                word = word + s[i];
                i++;
            }

            reverse(word.begin(), word.end());
            if(word.length() > 0)
                result += " " + word;
        }  

        return result.substr(1);
    }
};