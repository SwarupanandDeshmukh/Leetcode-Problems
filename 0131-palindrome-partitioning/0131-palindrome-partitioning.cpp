class Solution {
public:

    bool pali(string &s)
    {
        int l = 0;
        int r = s.length()-1;
        while(l < r)
        {
            if(s[l] == s[r])
            {
                l++;
                r--;
            }
            else
                return false;
        }

        return true;
    }
    void helper(string s, vector<string> &partition, vector<vector<string>> &res)
    {
        if(s.length() == 0)
        {
            res.push_back(partition);
            return;
        }
        for(int i = 0; i<s.length(); i++)
        {
            string p = s.substr(0,i+1);

            if(pali(p))
            {
                partition.push_back(p);
                helper(s.substr(i+1), partition, res);
                partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> partition;
        vector<vector<string>> res;
        helper(s, partition, res);

        return res;
    }
};