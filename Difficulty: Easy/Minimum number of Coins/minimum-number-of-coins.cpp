class Solution {
  public:
    int findMin(int n) {
        // code here
        int ten = n / 10;
        int five = (n % 10) / 5;
        int two = ((n % 10) % 5) / 2;
        int one = (((n % 10) % 5) % 2) / 1;
        
        return (ten + five + two + one);
        
        
    }
};