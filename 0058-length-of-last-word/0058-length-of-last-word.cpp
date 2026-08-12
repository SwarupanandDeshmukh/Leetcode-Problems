class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int n = s.length();

        string word = "";
        vector<string> res;
        for(int i = 0; i<n; i++)
        {
            if(s[i] != ' ')
            {   
                word += s[i];
            }
            else
            {
                if(word != "")
                {
                    res.push_back(word);
                    word = "";
                }
            }
        }

        res.push_back(word);

        for(string s : res)
            cout << s << endl;

        n = res.size();

        if(res[n-1].size() == 0)
            return res[n-2].size();
        


        return res[n-1].size();
    }
};