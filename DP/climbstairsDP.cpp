// class Solution { //space optimization after tabulation
// public:
//     int climbStairs(int n) {
//         int prev2=0,prev=1,curr=0;
//         for(int i=1;i<=n;i++)
//         {
//             curr=prev+prev2;
//             prev2=prev;
//             prev=curr;
//         }
//         return prev;

//     }
// };
// memoization
class Solution {
public:
    int t[46];
    int solve(int n){
        if(n<0)
            return 0;
        if(n==0)
            return 1;
        if(t[n]!=-1) 
            return t[n];
        int one_step=solve(n-1);
        int two_step=solve(n-2);

        return t[n]=one_step+two_step;
    }
    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
    }
};