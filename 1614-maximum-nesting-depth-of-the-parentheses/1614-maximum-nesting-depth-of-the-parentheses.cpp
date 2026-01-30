class Solution {
public:
    int maxDepth(string s) {
        stack<char> stck;
        int maxcnt = INT_MIN;
        int cnt = 0; 
        for(char c : s)
        {
            if(c == '(')
            {
                stck.push(c);
                cnt++;
            }
            else if(c == ')')
            {
                maxcnt = max(maxcnt,cnt);
                cnt--;
                stck.pop();
            }
        }
        if(maxcnt == INT_MIN)
            return 0;
        return maxcnt;
    }
};