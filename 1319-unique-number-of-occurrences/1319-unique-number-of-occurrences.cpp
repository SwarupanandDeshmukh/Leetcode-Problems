class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
       unordered_map<int,int> m;

       for(int val : arr)
            m[val]++;
        
        unordered_set<int> s;

        for(auto val:m)
            s.insert(val.second);
        
        if(m.size() == s.size())
            return true;
        else
            return false;

    }
};