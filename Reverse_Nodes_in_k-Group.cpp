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
    bool hasKnodes(ListNode* head,int k)
    {
        int count=0;
        while(count<k)
        {
            if(head==NULL)
                return false;
            head=head->next;
            count++;
        }
        return true;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev=NULL,*curr=head,*next=head;
        int count=0;
        while(curr!=NULL&&count<k)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(hasKnodes(curr,k))
        head->next=reverseKGroup(curr,k);
        else
            head->next=curr;
        return prev;
    }
};
