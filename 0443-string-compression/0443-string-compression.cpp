class Solution {
public:
    int compress(vector<char>& chars) {
        
        int n = chars.size();
        string s = "";
        int i = 0;
        while(i < n)
        {   
            int current = chars[i];
            int cnt = 0;
            while(i<n &&  chars[i] == current)
            {
               cnt++;
               i++;
            }
            s.push_back(current);
            if(cnt > 1 && cnt < 10)
                s.push_back('0' + cnt);
            else if(cnt >= 10)
            {
                string s2 = to_string(cnt);
                for(char c: s2)
                    s.push_back(c);
            
            }
        }

        chars.assign(s.begin(), s.end());

        return chars.size();
    }
};