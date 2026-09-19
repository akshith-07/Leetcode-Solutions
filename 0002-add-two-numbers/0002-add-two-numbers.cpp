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
        ListNode* output = new ListNode(0);
        ListNode* dummy = output;
        int carry =0;
        ListNode* newNode;
        while(l1!=nullptr || l2!=nullptr){
            if(l1!=nullptr && l2!=nullptr){
                carry = l1->val + l2->val + carry;
                newNode = new ListNode(carry%10);
                cout<<newNode->val<<" ";
                carry = carry/10;
            }else if(l1==nullptr && l2!=nullptr){
                carry = l2->val + carry;
                newNode = new ListNode(carry%10);
                cout<<newNode->val<<" ";
                carry = carry/10;
            }else if(l1!=nullptr && l2==nullptr){
                carry = l1->val + carry;
                newNode = new ListNode(carry%10);
                cout<<newNode->val<<" ";
                carry = carry/10;
            }
        
            output->next = newNode;
            output=output->next;
           
            if(l1!=nullptr)l1=l1->next;
            if(l2!=nullptr)l2=l2->next;
        }

        if(carry!=0) {
            newNode = new ListNode(carry);
            output->next = newNode;

        }

        return dummy->next;

    }

};