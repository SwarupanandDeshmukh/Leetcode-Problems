class Solution {
  public:
  
    struct activity
    {
        int s;
        int e;
    };
    
    static bool cmp(activity a, activity b)
    {
        return a.e < b.e;
    }
    
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        
        int n = finish.size();
        vector<activity> act(n);
        
        for(int i = 0; i<n; i++)
        {
            act[i] = {start[i], finish[i]};
        }
        
        
       
        sort(act.begin(), act.end(), cmp);
        
        int currend = act[0].e;
        
        int cnt = 1;
        for(int i = 1; i<n; i++)
        {
            if(act[i].s > currend)
            {
                cnt++;
                currend = act[i].e;
            }
        }
        
        return cnt;
    }
};