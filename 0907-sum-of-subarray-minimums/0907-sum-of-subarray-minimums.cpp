class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        stack<int> s1;
        stack<int> s2;
        vector<int> left(n, -1);
        vector<int> right(n, -1);

        for(int i = 0; i<n; i++)
        {
            while(!s1.empty() && arr[s1.top()] > arr[i])
            {
                s1.pop();
            }

            left[i] = s1.empty() ? -1 : s1.top();
            s1.push(i);
        }

        for(int i = n-1; i>=0; i--)
        {
            while(!s2.empty() && arr[s2.top()] >= arr[i])
            {
                s2.pop();
            }

            right[i] = s2.empty() ? -1 : s2.top();
            s2.push(i);
        }

        int sum = 0;
        for(int i = 0; i<n; i++)
        {
            int leftcnt = i - left[i];
            int rightcnt = right[i] == -1 ? n-i : (right[i] - i);

            sum = (sum + ((arr[i] * leftcnt) % 10000000007 * rightcnt)) % 1000000007;
        }   

        return sum;

    }
};