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

// Divide and Conquer TC(Log(K)*N) SC(log(K))
    ListNode* merge2List(ListNode* l1, ListNode* l2){
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        if(l1->val<=l2->val){
            l1->next = merge2List(l1->next,l2);
            return l1;
        }else{
            l2->next = merge2List(l1,l2->next);
            return l2;
        }   
    }

    ListNode* partition_merge(int start, int end, vector<ListNode*>& lists){
        if(start==end)
            return lists[start];
        int mid=start+(end-start)/2;
        ListNode* L1 = partition_merge(start,mid,lists);
        ListNode* L2 = partition_merge(mid+1,end,lists);

        return merge2List(L1,L2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0)
            return NULL;
        ListNode* ans = partition_merge(0,n-1,lists);
        return ans;
    }
};