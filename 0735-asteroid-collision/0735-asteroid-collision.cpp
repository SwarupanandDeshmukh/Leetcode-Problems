class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> v;
        stack<int> s;

        for(int i = 0; i<n; i++)
        {

            while(!s.empty() && (s.top() > 0 && asteroids[i] < 0 && abs(s.top()) < abs(asteroids[i])))
            {
                s.pop();
                v.pop_back();
            }
            
            if(s.empty())
            {
                s.push(asteroids[i]);
                v.push_back(asteroids[i]);
                continue;
            }
            
            if(asteroids[i] < 0 && s.top() > 0 && abs(s.top())  > abs(asteroids[i]))
                continue;
            
             if(asteroids[i] < 0 && s.top() > 0 && abs(s.top())  == abs(asteroids[i]))
            {
                s.pop();
                v.pop_back(); 
                continue;
            }

            s.push(asteroids[i]);
            v.push_back(asteroids[i]);
            
        }

        return v;
    }
};