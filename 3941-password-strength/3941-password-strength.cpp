class Solution {
public:
    int passwordStrength(string password) {
        
        unordered_map<char, int> m;

        for(char c : password)
        {
            m[c]++;
        }

        int sum = 0;
        for(const auto pair: m)
        {
            char c = pair.first;
            int cnt = pair.second;

            if(c >= 'a' && c <= 'z' && cnt >= 1)
                sum += 1;

            else if(c >= 'A' && c <= 'Z' && cnt >= 1)
                sum += 2;

            else if(c >= '0' && c <= '9' && cnt >= 1)
                sum += 3;

            else
                sum += 5;
        }

        return sum;

        
    }
};