//  using DUMMY NODE
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode dummy(0);
//         ListNode* l3= &dummy;
//         while(list1 && list2)
//         {
//             if(list1->val <= list2->val)
//             {
//                 l3->next=list1;
//                 list1=list1->next;
//             }
//             else
//             {
//                 l3->next= list2;
//                 list2=list2->next;
//             }
//             l3=l3->next;
//         } 
//         if(list1)
//             l3->next=list1;
//         if(list2)
//             l3->next=list2;
//         return dummy.next;
//     }
// };


//USING RECURSION
class Solution {
public:
    ListNode* merge2List(ListNode* l1, ListNode* l2){
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        if(l1->val<l2->val){
            l1->next = merge2List(l1->next,l2);
            return l1;
        }else{
            l2->next = merge2List(l1,l2->next);
            return l2;
        }   
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans=merge2List(list1,list2);
        return ans;
    }
};