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

    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL)
            return NULL;

        if(head->next == NULL)
            return head;
        
        if(k == 0)
            return head;
        
        ListNode *res = NULL;
        
        ListNode *temp = head;
        ListNode *tail = head;
        int n = 0;
        while(temp != NULL)
        {   
            n++;
            temp = temp->next;
        }

       while(tail->next != NULL)
            tail = tail->next;

        
        k = k % n;
        if(k == 0)
            return head;

        int s = n - k;
        ListNode *p = head;
        for(int i = 1; i<s; i++)
            p = p->next;
        
        ListNode *newhead = p->next;
        tail->next = head;
        p->next = NULL;

        return newhead;

        

    }
};