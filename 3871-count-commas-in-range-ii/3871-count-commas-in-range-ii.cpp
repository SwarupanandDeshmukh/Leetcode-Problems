class Solution {
public:
    long long countCommas(long long n) {
        
        
        long long low = 1000;
        int comma = 1;
        long long cnt = 0;

        while(low <= n)
        {
            long long up = (low * 1000) - 1;
            if(up > n)
                up = n;
            cnt += (up - low + 1) * comma;
            low = low * 1000;
            comma++;
        }

        return cnt;
    }
};