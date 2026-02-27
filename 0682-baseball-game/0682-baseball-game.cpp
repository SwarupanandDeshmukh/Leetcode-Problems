class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int n = operations.size();

        for(string s: operations)
        {
            if(s != "C" && s!= "D" && s != "+")
            {
                int val = stoi(s);
                st.push(val);
            }
            else if(s == "C")
                st.pop();
            else if(s == "D")
            {
                int res = st.top() * 2;
                st.push(res);
            }
            else
            {
                int v2 = st.top();
                st.pop();
                int v1 = st.top();
                st.pop();

                int r = v1 + v2;
                st.push(v1);
                st.push(v2);
                st.push(r);
            }
        }

        int sum = 0;
        while(!st.empty())
        {
            sum = sum + st.top();
            st.pop();
        }

        return sum;

    }
};