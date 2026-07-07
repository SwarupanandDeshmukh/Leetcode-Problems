class Solution {
public:
    long long sumAndMultiply(int n) {
        
        int dig = 0;
        string s = "";
        int sum = 0;

        if(n == 0)
            return 0;
        while(n> 0)
        {
            dig = n % 10;
            if(dig != 0)
            {
                sum += dig;
                char c = dig + '0';
                s = c + s;
            }
            n = n / 10;
                
        }

        long long newn = stoll(s);

        long long res = newn * sum;
        return res;
    }
};