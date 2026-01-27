class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();

        int j = n -1;
        while( j >=0)
        {
            int number = num[j] - '0';
            if(number % 2 !=0)
            {
                return num.substr(0,j+1);
            }
            j--;
        }

        return "";
    }
};