/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        if(head->next == NULL)
            return head->val;

        ListNode *temp = head;
        int cnt = 0;
        while(temp != NULL)
        {
            cnt++;
            temp = temp->next;
        }

        int p = cnt -1;
        temp = head;
        int res = 0;
        while(temp != NULL)
        {
            res += temp->val * pow(2,p);
            p = p -1;
            temp = temp->next;
        }

        return res;
        
    
    }
};