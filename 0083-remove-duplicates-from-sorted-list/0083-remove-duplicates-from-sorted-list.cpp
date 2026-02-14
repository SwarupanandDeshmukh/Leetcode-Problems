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
        ListNode *n = new ListNode(v);
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
    ListNode* deleteDuplicates(ListNode* head) {
            if(head == NULL)
                return {};
            
            vector<int> v;
            ListNode *res = NULL;
            ListNode *temp1 = head;

            while(temp1 != NULL)
            {
                if (!binary_search(v.begin(), v.end(), temp1->val))
                {
                    v.push_back(temp1->val);
                    insert(res, temp1->val);
                }
                temp1 = temp1->next;
            }

            return res;

    }
};