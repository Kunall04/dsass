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
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* res=new ListNode(0);
        ListNode* ans=res;
        int sum;
        int carry=0; //Initialize carry with zero

// Add digits of both the numbers till both the number exists
// The loop will stop if either any one or both the numbers are finished
        while(temp1 && temp2){ 
            sum=temp1->val+temp2->val+carry;
            if(sum>=10){
                sum-=10;
                carry=1;
            }
            else
                carry=0;
            res->next=new ListNode(sum); 
            res=res->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
      
// If number 1 has more digits than number 2
        while(temp1){
            sum=temp1->val+carry;
            if(sum==10){
                sum=0;
            }
            else
                carry=0;
            res->next=new ListNode(sum);
            res=res->next;
            temp1=temp1->next;
        }

// If number 2 has more digits than number 1
      while(temp2){
            sum=temp2->val+carry;
            if(sum==10){
                sum=0;
            }
            else
                carry=0;
            res->next=new ListNode(sum);
            res=res->next;
            temp2=temp2->next;
        }

// Add carry to a new node in last if both the numbers has finished but carry is still one
        if(carry)
            res->next=new ListNode(carry);
            
        return ans->next;
    }
};
