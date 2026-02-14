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

    void insert(ListNode* &res, int v)
    {
        ListNode* n = new ListNode(v);
        if(res == NULL)
        {
            res = n;
            res->next = NULL;
            return;
        }

        ListNode *temp = res;
        while(temp->next != NULL)
            temp = temp->next;
                
        temp->next = n;
        temp = n;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        if(list1 == NULL && list2 == NULL)
            return {};

        ListNode* res = NULL;
        ListNode *temp1 = list1;
        ListNode *temp2 = list2;

        while(temp1 != NULL && temp2 != NULL)
        {
            if(temp1->val <= temp2->val)
            {
                insert(res, temp1->val);
                temp1 = temp1->next;
            }
            else if(temp2->val < temp1->val)
            {
                insert(res, temp2->val);
                temp2 = temp2->next;
            }
        }

        while(temp1 != NULL)
        {
            insert(res, temp1->val);
            temp1 = temp1->next;
        }

        while(temp2 != NULL)
        {
            insert(res, temp2->val);
            temp2 = temp2->next;
        }

        return res;
        
    }
};