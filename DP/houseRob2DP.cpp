class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>t(n+1,0);
        //t[i] is the max stolen till i house;
        //CASE 1
        t[0]=0;
        for(int i=1;i<=n-1;i++){
            int steal = nums[i-1]+((i-2>=0)?t[i-2]:0);
            int skip = t[i-1];
            t[i]=max(steal,skip);
        }
        int result1=t[n-1];
        t.clear();
        t[0]=0;//no house no profit;
        t[1]=0;
        for(int i=2;i<=n;i++){
            int steal = nums[i-1]+((i-2>=0)?t[i-2]:0);
            int skip = t[i-1];
            t[i]=max(steal,skip);
        }
        int result2=t[n];
        return max(result1,result2);
    }
};


// class Solution {
//     int robber(vector<int>nums)
//     {
//         int n=nums.size();
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
// public:
//     int rob(vector<int>& nums) {
//         vector<int> t1,t2;
//         if(nums.size()==1) return nums[0];
//         for(int i=0;i<nums.size();i++)
//         {
//             if(i!=0) t1.push_back(nums[i]);
//             if(i!=nums.size()-1) t2.push_back(nums[i]);
//         }
//         return max(robber(t1),robber(t2));
//     }

// };