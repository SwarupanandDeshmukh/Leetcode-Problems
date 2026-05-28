class Solution {
public:

    static bool cmp(pair<int, int> p1, pair<int,int> p2)
    {
        return p1.second < p2.second;
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        
        vector<pair<int, int>> p;

        int n = pairs.size();
        for(int i = 0; i<n; i++)
        {
            pair<int, int> temp = {pairs[i][0], pairs[i][1]};
            p.push_back(temp);
        }

       sort(p.begin(), p.end(), cmp);

        int count = 1;

        pair<int,int> prev = p[0];

        for(int i = 1; i < p.size(); i++)
        {
            if(prev.second < p[i].first)
            {
                count++;
                prev = p[i];
            }
        }

        return count;


    }
};