class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
       int n = prices.size();
        vector<int> bestBuy(100000);
        bestBuy[0] = INT_MAX;  

        // find the best buy array
       for(int i = 1; i<n; i++)
       {
            bestBuy[i] = min(bestBuy[i-1], prices[i-1]);
       }

        //find the profit
        int maxi = 0;
       for(int i =0; i<n; i++)
       {
            int prof = prices[i] - bestBuy[i];
            if(prof > maxi)
                maxi = prof;
       }

       return maxi;

        

        
    }
};