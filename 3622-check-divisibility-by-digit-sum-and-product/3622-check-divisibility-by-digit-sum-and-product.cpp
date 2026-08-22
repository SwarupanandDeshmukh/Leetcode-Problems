class Solution {
public:
    bool checkDivisibility(int n) {
        
        int dsum = 0, dprod = 1;
        int temp = n;
        while(n > 0)
        {
            int rem = n % 10;
            dsum += rem;
            dprod *= rem;
            n = n / 10; 
        }

        if(temp % (dsum + dprod) == 0)
            return true;

        return false; 
    }
};