class Solution {
public:
    int maxArea(vector<int>& height) {
        int l =0;
        int r = height.size()-1;
        int mini = 0;
        int area = 0;
        int maxarea = 0;
        while(l < r)
        {
            mini = min(height[l],height[r]);
            area = mini * (r-l);
            if(area > maxarea)
            {
                maxarea = area;
            }
            if(mini == height[l] || height[l] == height[r])
                l++;
            else
                r--;
        }

        return maxarea;
    }
};