class Disjoint
{
    public:
        vector<int> parent;
        vector<int> rank;

        Disjoint(int n)
        {
            parent.resize(n);
            rank.resize(n, 0);
            for(int i = 0; i<n; i++)
            {
                parent[i] = i;
            }
        }


        int find(int x)
        {
            if(parent[x] == x)
                return x;
            
            return parent[x] = find(parent[x]);
        }

        void UnionByRank(int a, int b)
        {
            int parA = find(a);
            int parB = find(b);

            if(parA == parB)
                return;
            
            if(rank[parA] == rank[parB])
            {
                parent[parB] = parA;
                rank[parA]++;
            }
            else if(rank[parA] > rank[parB])
                 parent[parB] = parA;
            else
                parent[parA] = parB;
        }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    

        int n = accounts.size();
        Disjoint dj(n);
        unordered_map<string, int> emailNode;

        for(int i = 0; i<n; i++)
        {
            for(int j = 1; j<accounts[i].size(); j++)
            {
                string email = accounts[i][j];
                if(emailNode.find(email) == emailNode.end())
                {
                    emailNode[email] = i;
                }
                else
                    dj.UnionByRank(emailNode[email], i);
            }
        }

        unordered_map<int, vector<string>> nodeEmail;

        for(const auto pair : emailNode)
        {
            string mail = pair.first;
            int node = dj.find(pair.second);
            nodeEmail[node].push_back(mail);
        }
        
        vector<vector<string>> res;
        vector<string> temp;
        for(const auto pair: nodeEmail)
        {
            int i = pair.first;
            sort(nodeEmail[i].begin(), nodeEmail[i].end());
            temp.push_back(accounts[i][0]);
            
            for(const auto mails: nodeEmail[i])
                temp.push_back(mails);
            
            res.push_back(temp);
            temp.clear();
    
        }



        return res;



    }
};