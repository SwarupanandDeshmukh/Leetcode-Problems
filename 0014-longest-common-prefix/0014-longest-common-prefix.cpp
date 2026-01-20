class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n =strs.size();

        string result = "";

        sort(strs.begin(),strs.end());

        string s1 = strs[0];
        string s2 = strs[strs.size() - 1];

        for(int i = 0; i<s1.length(); i++)
        {
            if(s1[i] == s2[i])
                result  = result + s1[i];
            else
                break;
        }
        return result;
       
    }
};