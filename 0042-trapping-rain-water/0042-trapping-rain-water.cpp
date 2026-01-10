class Solution {
public:
    int trap(vector<int>& height) {
        // vector<int> leftMax(20000);
        // vector<int> rightMax(20000);
        // int n = height.size();

        // leftMax[0] = height[0];
        // for(int i =1; i<n; i++)
        // {
        //     leftMax[i] = max(leftMax[i-1], height[i-1]);
        // }

        // rightMax[n-1] = height[n-1];
        // for(int i=n-2; i>=0; i--)
        // {
        //     rightMax[i] = max(rightMax[i+1], height[i+1]);
        // }

        // int waterTrapped = 0;
        // for(int i =0; i<n; i++)
        // {
        //     int curr = min(leftMax[i],rightMax[i]) - height[i];
        //     if(curr > 0)
        //     {
        //         waterTrapped = waterTrapped + curr;
        //     }
        // }

        // return waterTrapped;

        int n = height.size();

        int l = 0;
        int r = n -1;
        int lMax = 0, rMax = 0;
        int waterTrapped = 0;
        while(l < r)
        {
            lMax = max(lMax, height[l]);
            rMax = max(rMax, height[r]);
            if(lMax < rMax)
            {
                int curr = lMax - height[l];
                if(curr > 0)
                {
                    waterTrapped = waterTrapped + curr;
                }
                l++;
            }
            else
            {
                int curr = rMax - height[r];
                if(curr > 0)
                {
                    waterTrapped = waterTrapped + curr;
                }
                r--;
            }
        }

        return waterTrapped;
        

    }
};