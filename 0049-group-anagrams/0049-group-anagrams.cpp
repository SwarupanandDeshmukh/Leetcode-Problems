class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string,vector<string>> m;

        if(strs[0] == "" && strs.size() == 1)
            return {{""}};
        
        
        for(string s : strs)
        {
            string org = s;
            sort(s.begin(), s.end()); 
            m[s].push_back(org);
        }

        vector<vector<string>> result;

        for(const auto& pair : m)
        {
            result.push_back(pair.second);
        }

        return result;
        
    }
};