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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
         ListNode *res = NULL;



        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
       

        int carry = 0;
        int sum = 0;
        while(temp1 != NULL && temp2 != NULL)
        {
            
            sum = temp1->val + temp2->val + carry;
            carry = sum / 10;
            insert(res, sum%10);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }


        while(temp1 != NULL)
        {
            sum = temp1->val + 0 + carry;
            carry = sum /10;
            insert(res, sum%10);
            temp1 = temp1->next;
        }

        while(temp2 != NULL)
        {
            sum = temp2->val + 0 + carry;
            carry = sum /10;
            insert(res, sum%10);
            temp2 = temp2->next;
        }

        if(carry != 0)
        insert(res,carry);

        return res;
    }
};