class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i = 1; i<=n; i++)
        {
            q.push(i);
        }

        int cnt = 0;
        
        while(q.size() > 1)
        {
            for(int i = 1; i<k; i++)
            {
                q.push(q.front());
                q.pop();
            }

            q.pop();
        }

        return q.front();
    }
};