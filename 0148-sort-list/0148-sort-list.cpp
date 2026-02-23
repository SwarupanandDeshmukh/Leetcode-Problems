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

    ListNode* middle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* &leftSorted, ListNode* rightSorted)
    {
        if(!leftSorted) return rightSorted;
        if(!rightSorted) return leftSorted;

        ListNode* head;

        if(leftSorted->val <= rightSorted->val)
        {
            head = leftSorted;
            leftSorted = leftSorted->next;
        }
        else
        {
            head = rightSorted;
            rightSorted = rightSorted->next;
        }

        ListNode *tail = head;
        while(leftSorted != NULL && rightSorted != NULL )
        {
            if(leftSorted->val <= rightSorted->val)
            {
                tail->next = leftSorted;
                leftSorted = leftSorted->next;
            }
            else
            {
                tail->next = rightSorted;
                rightSorted = rightSorted->next;
            }
            tail = tail->next;
        }

        if(leftSorted)
            tail->next = leftSorted;
        
        if(rightSorted)
            tail->next = rightSorted;

        return head;
    }

    ListNode* sortList(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *mid = middle(head);

        ListNode *right = mid->next;
        mid->next = NULL;
        ListNode *leftSorted = sortList(head);
        ListNode *rightSorted = sortList(right);

        ListNode *merged = merge(leftSorted, rightSorted);

        return merged;
    }
};