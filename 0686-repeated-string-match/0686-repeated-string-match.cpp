class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int m = b.length();
        int orig_n = a.length();

        
        vector<int> lps(m);
        int len = 0;
        int i = 1;
        while(i < m) {
            if(b[i] == b[len]) {
                lps[i++] = ++len;
            } else {
                if(len != 0) len = lps[len - 1];
                else lps[i++] = 0;
            }
        }

        
        string temp = a;
        while (temp.length() < m + 2 * orig_n) {
            temp += a;
        }

       
        i = 0; 
        int j = 0; 
        int current_n = temp.length();

        while(i < current_n) {
            if(temp[i] == b[j]) {
                i++;
                j++;
            }

            if(j == m) {
                int idx = i - j;
                
                return (idx + m + orig_n - 1) / orig_n;
            } else if(i < current_n && temp[i] != b[j]) {
                if(j != 0) j = lps[j - 1];
                else i++;
            }
        }

        return -1;
    }
};