/*
struct Job
{
    int id;	 // Job Id
    int deadline; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution {
  public:
    
    static bool cmp(Job a, Job b)
    {
        return a.profit > b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) {
        // code here
        
        vector<int> res;
        
        sort(arr, arr+n, cmp);
        
        int maxdead = 0;
      
        
        for(int i = 0; i<n ;i++)
        {
            maxdead = max(maxdead, arr[i].deadline);
        }
        
        int totalcost = 0;
        vector<int> slot(maxdead, -1);
        int cnt = 0;
        
        for(int i = 0; i<n; i++)
        {
            for(int j = arr[i].deadline -1; j>=0; j--)
            {
                if(slot[j] == -1)
                {
                    slot[j] = arr[i].id;
                    totalcost += arr[i].profit;
                    cnt++;
                    break;
                }
            }
        }
        
        res.push_back(cnt);
        res.push_back(totalcost);
        
        return res;
        
    }
};