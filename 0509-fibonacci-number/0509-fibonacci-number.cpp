class Solution {
public:
    int newfib(int n, vector<int> &dp)
    {
        if(n <=1)
            return n;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = newfib(n-1, dp) + newfib(n-2, dp);
    }

    int fib(int n) {
     vector<int> dp(n+1,-1);
    return newfib(n, dp);
    }
};