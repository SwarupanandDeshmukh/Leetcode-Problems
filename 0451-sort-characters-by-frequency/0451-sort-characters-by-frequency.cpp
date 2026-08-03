class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> m;

        for(char c : s)
        {
            m[c]++;
        }

        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;

        for(auto pair : m)
        {
            pq.push({pair.second, pair.first});
        }

        string res = "";
        while(!pq.empty())
        {
            int cnt = 0;
            auto pair = pq.top();
            pq.pop();

            char c = pair.second;
            int freq = pair.first;

            while(cnt < freq)
            {
                res += c;
                cnt++;
            }
        }

        return res; 
    }
};