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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* mergedList = new ListNode(0);

        ListNode* temp = mergedList;

        ListNode* newNode;

        while(list1!=nullptr && list2 != nullptr){
        
            if(list1->val == list2->val){
                newNode = new ListNode(list1->val);
                temp->next = newNode;
                list1= list1->next;
            }else if(list1->val < list2->val){
                newNode = new ListNode(list1->val);
                temp->next = newNode;
                list1=list1->next;
            }else if(list1->val > list2->val){
                newNode = new ListNode(list2->val);
                temp->next = newNode;
                list2=list2->next;
            }
            temp = temp->next;
        }

        while(list1!=nullptr){
            newNode = new ListNode(list1->val);
            temp->next = newNode;
            list1 = list1->next;
            temp=temp->next;
        }
        while(list2!=nullptr){
            newNode = new ListNode(list2->val);
            temp->next = newNode;
            list2 = list2->next;
            temp=temp->next;
        }   

    return mergedList->next;
        
    }
};