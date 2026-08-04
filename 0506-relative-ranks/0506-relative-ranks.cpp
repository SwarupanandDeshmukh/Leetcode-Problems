class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        
        int n = score.size();

        priority_queue<int, vector<int>> pq;

        for(int i = 0; i<n; i++)
        {
            pq.push(score[i]);
        }

        unordered_map<int, string> m;
        
        int cnt = 0;
        while(!pq.empty())
        {
            int num = pq.top();
            pq.pop();            
            cnt++;

            if(cnt == 1)
                m[num] = "Gold Medal";
            else if(cnt == 2)
                m[num] = "Silver Medal";
            else if(cnt == 3)
                m[num] = "Bronze Medal";
            else
                m[num] = to_string(cnt);
        }

        vector<string> res;
        for(int i = 0; i<n; i++)
        {
          res.push_back(m[score[i]]);
        }

        return res;

    }
};