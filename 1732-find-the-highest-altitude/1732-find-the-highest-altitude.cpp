class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int n = gain.size();
        int maxi = 0;
        int netval = gain[0];
        if(netval > 0)
            maxi = netval;

        for(int i = 1; i<n; i++)
        {
            netval = netval + gain[i];
            maxi = max(maxi, netval);
        }

        return maxi;

    }
};