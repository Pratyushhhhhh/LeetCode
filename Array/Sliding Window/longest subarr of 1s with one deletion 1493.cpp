class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0,zeros=0, mlen=0;
        int n= nums.size();
        while(j<n){
            if(nums[j]==0) zeros++;
            if(zeros>1){
                mlen= max(mlen,j-i);
                if(nums[i]==0)
                    zeros--;
                i++;
            }
            else
                mlen= max(mlen,j-i+1);
            j++;
        }
        return mlen-1;
    }
};