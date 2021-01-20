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
    int findMin(vector<ListNode*>& lists)
    {
        int index=-1;
        int min=INT_MAX;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i])
            {
                if(min>lists[i]->val)
                {
                    min=lists[i]->val;
                    index=i;
                }
            }
        }
        return index;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=NULL;
        ListNode* temp=NULL;
        while(1)
        {
            int ind=findMin(lists);
            if(ind==-1)
                break;
            if(!head)
            {
                head=lists[ind];
                temp=head;
                lists[ind]=lists[ind]->next;
                temp->next=NULL;
            }
            else
            {
                temp->next=lists[ind];
                lists[ind]=lists[ind]->next;
                temp=temp->next;
                temp->next=NULL;
            }
        }
        return head;
    }
};
