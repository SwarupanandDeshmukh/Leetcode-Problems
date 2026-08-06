class Solution {
public:
    int smallestNumber(int n, int t) {
        
    while( n <= 100)
    {
        int res = 0;
        int org = n;

        int ones = org % 10;
        if(n >= 10)
        {
            int tens = org / 10;
            res = (ones * tens) % t;
        }
        else
        {
            res = ones % t;
        }

        if(res == 0)
            break;
        
        n++;
    }

    return n;
        

    }
};