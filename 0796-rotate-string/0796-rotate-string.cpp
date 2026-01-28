class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int k = 1;
        while(true)
        {
            string org = s;
            reverse(org.begin(),org.end());
            reverse(org.begin(),org.end() - (n - k));
            reverse(org.begin() + k, org.end());

            if(org == goal)
            {
                return true;
            }

            else
            {  
                if(org == s)
                    break;
           }  
           k++;
        }

        return false;
    }
};