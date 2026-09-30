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

    ListNode* reverse(ListNode *newhead)
    { 
        ListNode *prev = NULL;
        ListNode *temp = newhead;
        ListNode *next = NULL;

        while(temp != NULL)
        {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverse(slow->next);

        ListNode *t1 = head;
        ListNode *t2 = newHead;

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