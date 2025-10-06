class Solution {
public:
    int fib(int n) {
        int a = 0;
        int b = 1;
        int cnt = 0;
        int c = 0;
        if(n == 1)
            return 1;

        while(cnt<n-1)
        {
            c = a + b;
            a = b;
            b = c;

            cnt++;
        }
        return c;
    }
};