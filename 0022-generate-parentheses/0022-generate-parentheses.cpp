class Solution {
public:

    void helper(int o, int c, string &s, vector<string> &ans)
    {
        if(o == 0 && c == 0)
        {
            ans.push_back(s);
            return;
        }

        if(o != 0)
        {
            s.push_back('(');
            helper(o-1, c,s,ans);
            s.pop_back();
        }

        if(c > o)
        {
            s.push_back(')');
            helper(o,c-1,s,ans);
            s.pop_back();
        }

        return;

    }
    vector<string> generateParenthesis(int n) {
        int o = n;
        int c = n;
        vector<string> ans;
        string s = "";
        helper(o, c, s, ans);

        return ans;
    }
};