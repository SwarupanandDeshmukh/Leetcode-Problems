class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        

        
        int count0 = 0;
        int count1 = 0;
        
        for(int i : students)
        {
            if(i == 0)
                count0++;
            else
                count1++;
        }

        // if any of the count is 0 break
        for(int i : sandwiches)
        {
            if(i == 0)
            {
                if(count0 == 0)
                    break;
                count0--;
            }
            else
            {
                if(count1 == 0)
                    break;
                count1--;
            }
        }

        return count0 + count1;
    }
};