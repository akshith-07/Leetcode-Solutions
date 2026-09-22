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
    int countNumOfNodes(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        return count;

    }
    ListNode* reverse(ListNode* head){
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr!=nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
       
        if(head==nullptr)
            return nullptr;

        int count = countNumOfNodes(head);
        k = k%count;
        if(k==0 || head->next == nullptr){
            return head;
        }
        ListNode* temp = reverse(head);
        

        ListNode* firstHalf = new ListNode(0);
        ListNode* refFirstHalf= firstHalf;
        ListNode* secondHalf = new ListNode(0);
        while(temp!=nullptr){
            if(k)
                firstHalf->next= temp;
            else {
                firstHalf->next = nullptr;
                secondHalf->next = temp;
                break;
            }
               
            temp=temp->next;
            firstHalf=firstHalf->next;
            k--;
        }

        ListNode* reverseFirstHalf = reverse(refFirstHalf->next);
        ListNode* reverseSecondHalf = reverse(secondHalf->next);   

        ListNode* temp1 = reverseFirstHalf;
    
        while(temp1->next!=nullptr){
            temp1=temp1->next;   
        }
        temp1->next = reverseSecondHalf;
        return reverseFirstHalf;
    }
};