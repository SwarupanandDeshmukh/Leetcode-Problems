class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        unordered_map<int, list<int>> adj;
        int n = graph.size();

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<graph[i].size(); j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }


        unordered_map<int, char> colors;
        unordered_map<int, bool> visited;
        queue<int> q;

        for(int i = 0; i<n; i++)
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] = true;
                colors[i] = 'R';

                  while(!q.empty())
                {
                    int cur = q.front();
                    q.pop();

                    for(const auto neigh : adj[cur])
                    {
                        if(visited[neigh] && colors[neigh] == colors[cur])
                            return false;
                        else if(!visited[neigh])
                        {
                            q.push(neigh);
                            visited[neigh] = true;

                            if(colors[cur] == 'R')
                                colors[neigh] = 'Y';
                            else
                                colors[neigh] = 'R';
                        }
                    }
                }

            }
        }

    return true;

    }
};