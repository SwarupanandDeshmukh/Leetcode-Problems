class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        vector<int> res;
        queue<int> q;
        
        int l=0;
        int r=0;
        while(r < n)
        {
            if(arr[r] < 0)
                q.push(arr[r]);
                
            if(r-l+1 < k)
                r++;
            else if(r-l+1 == k)
            {
                if(q.empty())
                    res.push_back(0);
                else
                    res.push_back(q.front());
                
                if(!q.empty() && q.front() == arr[l])
                    q.pop();
                
                l++;
                r++;
            }
        }
        
        return res;
        
    }
};