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
    void insert(ListNode *&res, int v)
    {
        ListNode * n = new ListNode(v);
        if(res == NULL)
        {
            res = n;
            res->next = NULL;
            return;
        }

        ListNode *t = res;
        while(t->next != NULL)
        {
            t = t->next;
        }

        t->next = n;
        t = n;
    }

    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL)
            return {};
        
        ListNode *temp = head;
        ListNode *res = NULL;
        int evencnt = 0;
        int oddcnt = 1;

        while(temp != NULL && temp->next != NULL)
        {
            if(evencnt % 2 == 0)
            {
                insert(res, temp->val);
                evencnt = evencnt + 2;
                temp = temp->next->next;
            }
        }

        if(temp != NULL)
            insert(res, temp->val);

        
        temp = head->next;
         while(temp != NULL && (temp->next == NULL ? temp->next != NULL : temp->next->next != NULL))
        {
            if(oddcnt % 2 != 0)
            {
                insert(res, temp->val);
                oddcnt = oddcnt + 2;
                temp = temp->next->next;
            }
        }


        if(temp != NULL)
            insert(res, temp->val);

        return res;

    }   
};