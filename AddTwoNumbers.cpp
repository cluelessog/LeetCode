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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = NULL;
        ListNode* head = NULL;
        int tempSum = 0;
        int carry = 0;
        ListNode *ans;
        while(l1 != NULL && l2 != NULL)
        {
            tempSum =  l1->val + l2->val + carry;
           
            if(tempSum > 9)
            {
                carry = 1;
                ans = new ListNode(tempSum%10);
            }
            else
            {
                carry = 0;
                ans = new ListNode(tempSum);
            }
            
            if(l3 == NULL)
            {
                l3 = ans;
                head = ans;
            }
            else
            {
                l3->next = ans;
                l3 = l3->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
            while(l1 != NULL)
            {
                int tmp = l1->val + carry;
                if(tmp > 9)
                {
                    carry = 1;
                    ans = new ListNode(tmp%10);
                }
                else
                {
                    carry = 0;
                    ans = new ListNode(tmp);
                }
                l3->next = ans;
                l3 = l3->next;
                l1 = l1->next;
            }
        
          while(l2 != NULL)
            {
                int tmp = l2->val + carry;
                if(tmp > 9)
                {
                    carry = 1;
                    ans = new ListNode(tmp%10);
                }
                else
                {
                    carry = 0;
                    ans = new ListNode(tmp);
                }
                l3->next = ans;
                l3 = l3->next;
                l2 = l2->next;
            }
        if(carry)
        {
            ListNode *ans = new ListNode(carry);
            l3->next = ans;
            l3 = l3->next;
        }
        return head;
    }
};
