class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> visited;
       while(n != 1)
       {    

            if(visited.contains(n))
                return false;
            
            visited.insert(n);

            int sum = 0;
            while(n > 0)
            {
                int rem = n % 10;
                int sq = rem * rem;
                sum += sq;
                n = n / 10;
            }

            n = sum;
       }

        return true;
    }
};