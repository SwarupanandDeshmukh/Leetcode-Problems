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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(left == right)
        {
            return head;
        }

        ListNode *leftptr = NULL;
        ListNode *rightptr = NULL;
        ListNode *temp = head;

        ListNode *leftptrPrev = NULL;

        int pos = 1;
       while(temp != NULL && pos < left)
       {
            leftptrPrev = temp;
            temp = temp->next;
            pos++;
           
       }
       leftptr = temp;



       while(temp != NULL && pos < right)
        {
            temp = temp->next;
            pos++;
        }

        rightptr = temp;


        if(leftptr != NULL && rightptr != NULL)
        {
            ListNode *afterRight = rightptr->next;
            ListNode *prev = leftptr;
            ListNode *temp = leftptr->next;
            ListNode *next = NULL;

            while(temp != afterRight)
            {
                next = temp->next;
                temp->next = prev;
                prev = temp;
                temp = next;
            }

            leftptr->next = afterRight;

            if(leftptrPrev == NULL)
            {
                head = rightptr;
            }
            else
                leftptrPrev->next = rightptr;
        }

        return head;

    }
};