class Solution {
public:

    void helper(int n, string s, vector<string> &res)
    {
        if(s.length() == n)
        {
            res.push_back(s);
            return;
        }

        for(char c : {'0', '1'})
        {
            if(!s.empty() && s.back() == '0' && c == '0')
                continue;
            

            s.push_back(c);
            helper(n, s,res);
            s.pop_back();
        }
    }

    vector<string> validStrings(int n) {
        vector<string> res;
        string s = "";
        helper(n,s,res);

        return res;
    }
};