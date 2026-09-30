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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *temp = head;

        if(head->next == NULL && n == 1)
            return NULL;
        
        int cnt = 0;
        while(temp != NULL)
        {
            temp = temp->next;
            cnt++;
        }


        int newcnt = cnt - n;

        if(newcnt == 0)
        {
            head = head->next;
            return head;
        }

        cout<< newcnt;

        int pos = 0;
        ListNode *prev = NULL;
        temp = head;
        while(temp != NULL && pos < newcnt)
        {
            prev = temp;
            temp = temp->next;
            pos++;
        }

        prev->next = temp->next;
        delete temp;

        return head;

        


        
    }
};