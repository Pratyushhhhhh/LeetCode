class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int minLen=INT_MAX,len=0,sum=0;
        int i=0,j=0;
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                minLen=min(minLen,j-i+1);
            
                sum-=nums[i];

                i++;
            }
            j++;
        }
        if (minLen == INT_MAX)
            return 0;
        return minLen;
    }
};

// brute tle O(N*N)
// int n=nums.size();
//         int sum=0, len=0, minlen=INT_MAX;
//         for(int i=0;i<n;i++){
//             sum=0;
//             for(int j=i;j<n;j++){
//                 sum+=nums[j];
                
//                 if(sum>=target){
//                     len=j-i+1;
//                     break;
//                 }
//             }
//             minlen=min(minlen,len);
//         }
//         if (minlen == INT_MAX)
//             return 0;

//         return minlen;