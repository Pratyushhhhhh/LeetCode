class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0, xor2 = 0;

        for (int i = 0; i < n; i++) {
            xor1 ^= i;
            xor2 ^= nums[i];
        }
        xor1 ^= n;
        return xor1 ^ xor2;
    }
};

//BRUTE
    //     for(int i=0;i<n+1;i++){ 
    //         int flag=0;
    //         for(int j=0;j<n;j++){
    //             if(nums[j]==i){
    //                 flag=1;
    //                 break;
    //             }
    //         }
    //         if(flag==0)
    //             return i;
    //     }
    // return 0;

//using vis O(n) sc O(n)
// vector<int>vis(n+1,0);

//         for(int i=0;i<n;i++)
//             vis[nums[i]]=1;

//         for(int i=0;i<n+1;i++){
//             if(vis[i]==0)
//                 return i;
//         }
//         return 0;

//Maths O(n)
// int sum=n*(n+1)/2;
//         int s=0;
//         for(int i=0;i<n;i++){
//             s+=nums[i];
//         }
//         return sum-s;