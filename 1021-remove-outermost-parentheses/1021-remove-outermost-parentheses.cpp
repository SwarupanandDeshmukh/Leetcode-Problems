class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;

        string res = "";
        for(char c: s)
        {
            if(c == '(')
            {
                if(st.size() > 0)
                {
                    res = res + c;
                }
                st.push(c);
            }
            else
            {
                if(st.size() > 1)
                {
                    res = res + c;
                }
                st.pop();
            }
            
        }

        return res;
    }
};