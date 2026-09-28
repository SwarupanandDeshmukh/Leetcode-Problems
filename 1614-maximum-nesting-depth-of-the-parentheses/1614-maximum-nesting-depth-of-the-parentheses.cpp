class Solution {
public:
    int maxDepth(string s) {
        
        int maxi = 0;
        stack<char> st;
        int n = s.size();

        for(int i = 0; i<n; i++)
        {
            if(s[i] == '(')
                st.push(s[i]);
            else if(s[i] == ')')
            {
                int stacksize = st.size();
                maxi = max(maxi, stacksize);
                st.pop();
            }
        }

        return maxi;

    }
};