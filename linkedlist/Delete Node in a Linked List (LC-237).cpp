/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Method 1(Preferred):

class Solution {
public:
    void deleteNode(ListNode* node){
// Copy next node's value 
        node->val=node->next->val;
// Skip the next node(deleting it from the linked list)
        node->next=node->next->next;
    }
};

// Method 2(Not Preffered):

class Solution {
public:
    void deleteNode(ListNode* node) {
// From the element that is to be deleted from the linked list, copy the values of the nodes next to them in the current node till we reach the second last node.
        while(node->next->next){
            node->val=node->next->val;
            node=node->next;
        }
// Push the value of the last node in the seconde last node and
// Delete the last node of the linked list
        node->val=node->next->val;
        node->next=NULL;
    }
};
