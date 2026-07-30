class Solution {
public:
    int pivotInteger(int n) {
        
        vector<int> pre(n);

        if(n == 1)
            return 1;
        
        pre[0] = 1; 
        for(int i = 2; i<=n; i++)
        {
            pre[i-1] = pre[i-2] + i;
        }

        int left = 0;
        int right = 0;
       for(int i = 0; i<n; i++)
       {
            if(i == 0)
            {
                left = 0;
                right = pre[n-1] - pre[i];
            }
            else if(i == n-1)
            {
                left = pre[i-1];
                right = 0;
            }
            else
            {
                left = pre[i-1];
                right = pre[n-1] - pre[i];
            }

            if(left == right)
            {
                return i+1;
            }
       }

       return -1;


    }
};