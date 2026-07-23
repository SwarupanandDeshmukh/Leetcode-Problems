class Solution {
public:
    int findLucky(vector<int>& arr) {

     unordered_map<int, int> m;
     int n = arr.size();

     for(int i =0; i<n; i++)
     {
        m[arr[i]]++;
     }   

    int maxi = INT_MIN;
    int num = 0;

    for(const auto pair: m)
    {
        if(pair.first == pair.second)
        {
            if(pair.second > maxi)
            {
                maxi = pair.second;
                num = pair.first;
            }
            
        }
    }

    if(num != 0)
        return num;
    
    return -1;

    }
};