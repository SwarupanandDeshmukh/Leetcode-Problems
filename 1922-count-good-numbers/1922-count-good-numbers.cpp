#define m 1000000007;
class Solution {
public:

    long long calc(long long x, long long y)
    {
        if(y == 0)
            return 1;
        
        long long ans = calc(x,y/2);
        if(y%2 == 0)
        {
            return (ans * ans) % m;
        }
        else
        {
            return (x * ans * ans) % m;
        }
    }


    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = n/2 + n%2;
        return (calc(5,even) * calc(4,odd)) % m;
    }
};