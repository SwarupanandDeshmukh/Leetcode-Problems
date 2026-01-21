class Solution {
public:
    string reverseWords(string s) {
        string word = "";
        stringstream ss(s);
        s = "";

        while(ss >> word)
        {
            s = s + word + " ";
        }

        if(!s.empty())
            s.pop_back();

        int l = 0;
        int r = s.length() - 1;
        while(l<r)
        {
            char t = s[l];
            s[l] = s[r];
            s[r] = t;
            l++;
            r--;
        }
        
        // word = "";
        // vector<string> v;
        // for(int i = 0; i<s.length(); i++)
        // {
        //     if(s[i] == ' ')
        //     {
        //         v.push_back(word);
        //         word = "";
        //         continue;
        //     }
        //     word = word + s[i];  
        // }

        // v.push_back(word);
        // s = "";
        // for(int i = 0; i<v.size(); i++)
        // {
        //     string ns = v[i];
        //     int l = 0;
        //     int r = ns.length() - 1;
        //     while(l<r)
        //     {
        //         char t = ns[l];
        //         ns[l] = ns[r];
        //         ns[r] = t;
        //         l++;
        //         r--;
        //     }
        //     s = s + ns + " ";
        // }

        // if(!s.empty())
        //     s.pop_back();

        // return s;

        string result = "";
        for(int i = 0; i<s.length(); i++)
        {
            string word = "";
            while(i<s.length() && s[i] != ' ')
            {
                word = word + s[i];
                i++;
            }

            reverse(word.begin(), word.end());
            if(word.length() > 0)
                result += " " + word;
        }  

        return result.substr(1);
    }
};