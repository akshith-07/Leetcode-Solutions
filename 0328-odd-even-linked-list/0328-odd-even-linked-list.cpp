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
    ListNode* oddEvenList(ListNode* head) {

        if(head==nullptr || head->next == nullptr){
            return head;
        }
        
        ListNode* oddHead = nullptr;
        ListNode* oddTail = nullptr;
        ListNode* evenHead = nullptr;
        ListNode* evenTail = nullptr;
        ListNode* temp = head;
        int count = 1;
        while(temp!=nullptr){
            ListNode* newNode = new ListNode(temp->val);
            if(count%2 == 1){
               if(oddHead==nullptr){
                    oddHead = newNode;
                    oddTail = newNode;
               }else{
                    oddTail->next = newNode;
                    oddTail = newNode;
               }
            }else{
                if(evenHead==nullptr){
                    evenHead = newNode;
                    evenTail = newNode;
                }else{
                    evenTail->next = newNode;
                    evenTail = newNode;
                }
            }
            count++;
            temp=temp->next;
        }

        oddTail->next = evenHead;

        return oddHead;
        
    }
};