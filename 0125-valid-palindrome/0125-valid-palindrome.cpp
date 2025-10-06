class Solution {
public:
    bool isPalindrome(string s) {
    string new_s;
    for(char c:s)
    {
        if(isalnum(c))
            new_s +=c;
    }

    for (char &c : new_s)
    {
        if (c >= 'A' && c <= 'Z')
            c = c + 32;
    }
    
    int i = 0;
    int n = new_s.length();
    while(i< (n-i-1))
    {
        if(new_s[i] == new_s[n-i-1])
            i++;
        else
            return false;  
    }
    return true;
    }
};