class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        stack<int> s1;
        stack<int> s2;
        vector<int> right(n ,-1);
        vector<int> left(n,-1);

        for(int i = 0; i<n; i++)
        {
            while(!s1.empty() && heights[s1.top()] >= heights[i])
            {
                s1.pop();
            }
            left[i] = s1.empty() ? -1 : s1.top();
            s1.push(i);
        }

        for(int i = n-1; i>=0; i--)
        {
            while(!s2.empty() && heights[s2.top()] >= heights[i])
            {
                s2.pop();
            }
            right[i] = s2.empty() ? n : s2.top();
            s2.push(i);
        }

        int maxarea = 0;
        for(int i = 0; i<n; i++)
        {
            int currarea = heights[i] * (right[i] - left[i] - 1);
            if(currarea > maxarea)
                maxarea = currarea;
        }   

        return maxarea;


    }
};