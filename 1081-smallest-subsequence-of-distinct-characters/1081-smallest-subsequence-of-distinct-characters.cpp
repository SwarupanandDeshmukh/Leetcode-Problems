class Solution {
public:
    string smallestSubsequence(string s) {
        
        int n = s.length();

        vector<int> lastIndex(26, -1);
        for(int i = n-1; i>=0; i--)
        {
            int idx = s[i] - 'a';
            if(lastIndex[idx] == -1)
                lastIndex[idx] = i;
        } 


        vector<int> visited(26, false);
        stack<char> st;
        for(int i = 0; i<n; i++)
        {   
            if(visited[s[i] - 'a'] == true)
                continue;
            
            while((!st.empty() && st.top() > s[i]))
            {
                int idx = st.top() - 'a';
                if(lastIndex[idx] > i)
                {
                    st.pop();
                    visited[idx] = false;
                }
                else
                    break;
            }
            if(visited[s[i] - 'a'] == false)
            {
                st.push(s[i]);
                visited[s[i] - 'a'] = true;
            }

        }

        string res;
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;

    }
};