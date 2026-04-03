class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        queue<int> q;
        vector<int> res(n,0);

        for(int i = 0; i<n; i++)
        {
            q.push(i);
        }

        sort(deck.begin(), deck.end());

        for(int i = 0; i<n; i++)
        {
            res[q.front()] = deck[i];
            q.pop();
            int v = q.front();
            q.pop();
            q.push(v);
        }

        return res;
    }
};