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

// Method 1(Preferred Approach):

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
// When the fast pointer points to the last node or goes beyond last node, the slow pointer points to the middle node
// Its because when the slow pointer moves one node ahead, the fast pointer moves two nodes ahead covering double distance
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};

// Method 2(Brute Force) :

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int count=0;
// Count the total number of nodes present in the list
        while(temp){
            count++;
            temp=temp->next;
        }
        int mid=count/2+1;
        int nodecount=1;
// Find the middle node (nodecount equals to the middle of count)
        while(head){
            if(nodecount==mid)
                return head;
            nodecount++;
            head=head->next;
        }
        return NULL;
    }
};
