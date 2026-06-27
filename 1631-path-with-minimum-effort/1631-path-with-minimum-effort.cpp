class Solution {
public: 
    
    bool valid(int x, int y, int m, int n)
    {
        if(x>=0 && x<m && y>=0 && y<n)
            return true;
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> effort(m, vector<int> (n, INT_MAX));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0,0}});
        effort[0][0] = 0;

        while(!pq.empty())
        {
            const auto coor = pq.top();
            pq.pop();

            int curreff = coor.first;
            int x = coor.second.first;
            int y = coor.second.second;

            if(valid(x+1, y, m,n))
            {
                int eff = abs(heights[x][y] - heights[x+1][y]);
                int neweff = max(curreff, eff);

                if(neweff < effort[x+1][y])
                {
                    effort[x+1][y] = neweff;
                    pq.push({neweff, {x+1,y}});
                }
            }

            if(valid(x-1, y,m, n))
            {
                int eff = abs(heights[x][y] - heights[x-1][y]);
                int neweff = max(curreff, eff);

                if(neweff < effort[x-1][y])
                {
                    effort[x-1][y] = neweff;
                    pq.push({neweff, {x-1,y}});
                }
            }

            if(valid(x, y-1,m, n))
            {
                int eff = abs(heights[x][y] - heights[x][y-1]);
                int neweff = max(curreff, eff);

                if(neweff < effort[x][y-1])
                {
                    effort[x][y-1] = neweff;
                    pq.push({neweff, {x,y-1}});
                }
            }

            if(valid(x, y+1,m, n))
            {
                int eff = abs(heights[x][y] - heights[x][y+1]);
                int neweff = max(curreff, eff);

                if(neweff < effort[x][y+1])
                {
                    effort[x][y+1] = neweff;
                    pq.push({neweff, {x,y+1}});
                }
            }
        }

        return effort[m-1][n-1];


    }

   
};