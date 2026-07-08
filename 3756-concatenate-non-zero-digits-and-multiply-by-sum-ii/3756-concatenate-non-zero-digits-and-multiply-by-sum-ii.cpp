#define MOD 1000000007
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        
        int m = s.length();
        vector<long long> digitSum(m, 0);
        digitSum[0] = s[0] - '0';
        vector<long long> numbers(m, 0);
        numbers[0] = s[0] - '0';
        vector<int> nonZeroes(m, 0);
        nonZeroes[0] = (s[0] != '0') ? 1: 0;
        vector<long long> powers(m+1, 0);
        powers[0] = 1;
        


        for(int i = 1; i<m; i++)
        {
            if(s[i] == '0')
            {
                digitSum[i] = digitSum[i-1];
                numbers[i] = numbers[i-1];
                nonZeroes[i] = nonZeroes[i-1];
            }
            else
            {
                digitSum[i] = (digitSum[i-1] + (s[i] - '0'));
                numbers[i] = ((numbers[i-1] * 10) + (s[i] - '0')) % MOD;
                nonZeroes[i] = nonZeroes[i-1] + 1;
            }
            powers[i] = (powers[i-1] * 10) % MOD;
        }

        vector<int> res;
        for(auto q: queries)
        {
            int l = q[0];
            long long r = q[1];
 
            long long sum = digitSum[r] - (l? digitSum[l-1] : 0);
            int k = nonZeroes[r] - (l ? nonZeroes[l-1]: 0);
            long long nbef = (l == 0) ? 0 : numbers[l-1];
            long long x =
            (numbers[r] - (1LL * nbef * powers[k] % MOD)  + MOD) % MOD;

        
            res.push_back((1LL * x * sum % MOD));

        }

        return res;

    

    }
};