class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n = num.length();
        if(n == k)
            return "0";
        
        stack<char> s;
        string news = "";
        int cnt = 0;
        for(int i = 0; i<n; i++)
        {
            if(cnt == k)
            {
                news = news + num.substr(i, n-i); 
                break;  
            }
            while(!s.empty() && cnt < k && s.top() > num[i])
            {
                if(news != "")
                    news.pop_back();
                s.pop();
                cnt++;
            }

            news.push_back(num[i]);
            s.push(num[i]);

        }

        while(cnt < k)
        {
            news.pop_back();
            cnt++;
        }
       
        int newn = news.length();
        int i = 0;
        while(i < newn && news[i] == '0')
        {
            i++;
        }
        if(i == newn)
            return "0";

        return news.substr(i, news.length() - i);

        

    }  
};