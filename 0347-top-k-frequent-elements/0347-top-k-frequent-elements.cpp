class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> m;

        for(int i = 0; i<n; i++)
        {
            m[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

        for(const auto pair: m)
        {
            int num = pair.first;
            int freq = pair.second;
            pq.push({freq, num});
        }

        int cnt = 0;
        vector<int> res;
        while(!pq.empty())
        {
            auto pair = pq.top();
            pq.pop();

            cnt++;
            res.push_back(pair.second);
            if(cnt == k)
                break;
        }

        return res;
    }
};