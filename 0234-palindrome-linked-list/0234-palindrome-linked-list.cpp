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

     void insert(ListNode * &res, int v)
    {
        ListNode *n = new ListNode(v);

        if(res == NULL)
        {
            res = n;
            res->next = NULL;
            return;
        }

        n->next = res;
        res = n;
    }

    bool isPalindrome(ListNode* head) {

        if(head == NULL)
            return {};

        ListNode *res = NULL;
        ListNode *temp = head;
        
        while(temp != NULL)
        {
            insert(res, temp->val);
            temp = temp->next;
        }

        ListNode *t1 = head;
        ListNode *t2 = res;

        while(t1 != NULL && t2 != NULL)
        {
            if(t1->val != t2->val)
                return false;
            t1 = t1->next;
            t2 = t2->next;
        }

        return true;

        
    }
};