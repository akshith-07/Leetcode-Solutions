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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count =0;
        ListNode* temp = head;
        ListNode* temp2 = head;

        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }


        int count2=0;
        int correctIndex = count-n;
        if(correctIndex==0){
            return head->next;
        }
        while(temp2->next!=nullptr){
            if(count2==correctIndex-1){
                temp2->next=temp2->next->next;
                break;
            }
            temp2=temp2->next;
            count2++;
            
        }

        return head;
    }
};