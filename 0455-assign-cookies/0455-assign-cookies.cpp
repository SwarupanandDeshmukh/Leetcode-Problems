class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        int n = g.size();
        int m = s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;
        int cnt = 0;
        while(i <n)
        {
            while(j < m)
            {
                if(s[j] >= g[i])
                {
                    cnt++;
                    i++;
                    j++;
                    break;
                }
                j++;
            }

            if(j >= m)
                break;
        }

        return cnt;
        
    }
};