class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        
        int sumOdd = 0;
        int sumEven = 0;
        int oddval = 1;
        int evenval = 2;
        for(int i = 0; i<n; i++)
        {
            sumOdd += oddval;
            sumEven += evenval;
            oddval += 2;
            evenval += 2;
        }

        
        int largeamong = max(sumOdd, sumEven);
        int smallamong = min(sumOdd, sumEven);
        int rem = largeamong % smallamong;

        while(rem > 0)
        {
            largeamong = smallamong;
            smallamong = rem;
            rem = largeamong % smallamong;
        }

        return smallamong;


    }
};