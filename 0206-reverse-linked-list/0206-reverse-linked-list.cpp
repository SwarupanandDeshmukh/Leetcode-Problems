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
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL)
            return {};

        ListNode *res = NULL;
        ListNode *temp = head;
        
        while(temp != NULL)
        {
            insert(res, temp->val);
            temp = temp->next;
        }

        return res;
    }
};