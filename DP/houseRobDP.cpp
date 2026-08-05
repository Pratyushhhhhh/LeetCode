class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>t(n+1,0);
        //t[i] is the max stolen till i house;
        t[0]=0;//no house no profit;
        t[1]=nums[0];

        for(int i=2;i<=n;i++){
            int steal = nums[i-1]+t[i-2];
            int skip = t[i-1];
            t[i]=max(steal,skip);
        }
        return t[n];
    }
};

// class Solution {// memoization and space optimization
//     // private:
//     // int robber(int ind,vector<int>nums,vector<int>&dp)
//     // {
//     //         if(ind==0) return nums[ind];
//     //         if(ind<0) return 0;
//     //         if(dp[ind]!=-1) return dp[ind];

//     //         int pick= nums[ind]+robber(ind-2,nums,dp);
//     //         int notpick= 0+robber(ind-1,nums,dp);

//     //         return dp[ind]=max(pick,notpick);
//     // }
// public:
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         // vector<int>dp(n,-1);
//         // robber(n-1,nums,dp);
//         // if(n==1)return nums[0];
//         // return dp[n-1];
//         int prev2=0,prev=nums[0];
//         for(int i=1;i<n;i++)
//         {
//             int take=nums[i];
//             if(i>1) take+=prev2;
//             int notake=0+prev;
//             int curr=max(take,notake);
//             prev2=prev;
//             prev=curr;
//         }
//         return prev;
//     }
// };