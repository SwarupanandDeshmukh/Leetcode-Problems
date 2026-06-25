class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        unordered_map<char, unordered_set<char>> adj;
        int n = words.size();
        unordered_map<char, int> indegree;
        
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<words[i].length(); j++)
            {
                if(indegree.find(words[i][j]) == indegree.end())
                    indegree[words[i][j]] = 0;
            }
        }
        
        for(int i = 0; i<n-1; i++)
        {
            string u = words[i];
            string v = words[i+1];
            
            int l = u.length() < v.length() ? u.length() : v.length();
            
            int j = 0;
            while(j < l)
            {
                if(u[j] != v[j])
                {
                    if(adj[u[j]].find(v[j]) == adj[u[j]].end())
                    {
                        adj[u[j]].insert(v[j]);
                        indegree[v[j]]++;
                    }
                    break;
                }
                j++;
            }
            
            if(j == l && u.length() > v.length())
                return "";
        }
        
        
        
        queue<char> q;
        
        for(const auto pair: indegree)
        {
            if(pair.second == 0)
                q.push(pair.first);
        }
        
        string res = "";
        
        while(!q.empty())
        {
            const auto alpha = q.front();
            q.pop();
            
            res = res+alpha;
            
            for(const auto neigh: adj[alpha])
            {
                indegree[neigh]--;
                if(indegree[neigh] == 0)
                    q.push(neigh);
            }
        }
        
        if(res.length() != indegree.size())
            return "";
        
        return res;
        
        
        
        
    }
};