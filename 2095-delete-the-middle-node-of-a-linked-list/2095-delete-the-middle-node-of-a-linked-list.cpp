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
    ListNode* deleteMiddle(ListNode* head) {
        
        int cnt = 0;
        if(head == NULL || head->next == NULL)
            return {};
    
        
        ListNode *temp = head;
        while(temp != NULL)
        {
            cnt++;
            temp = temp->next;
        }

        int mid = cnt / 2;

        int s = 0;
        ListNode *p = head;
        while(s < mid-1)
        {
            s++;
            p = p->next;
        }

        p->next = p->next->next;

        return head;
        

    }
};