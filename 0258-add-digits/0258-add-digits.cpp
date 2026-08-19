class Solution {
public:
    int addDigits(int num) {
        
        int sum = 0;
        int res = 0;

        while(true)
        {
            while(num > 0)
            {
                int rem = num % 10;
                sum += rem;
                num = num / 10;
            }
            res = sum;
            sum = 0;
            if(res >= 10)
            {
                num = res;
                continue;
            }
            else
                break;
        }

        return res;

        

    }
};