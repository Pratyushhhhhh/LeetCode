class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int i=0;
        int sum=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0] = -1;
        for(i=0;i<n;i++){
            sum+=nums[i];
            mp[sum]=i;
        }
        if(sum < x)
            return -1;
        int rem_sum = sum-x; 
        int longestSubArr=INT_MIN;
        sum=0;
        for(i=0;i<n;i++){
            sum+=nums[i];
            if(mp.find(sum-rem_sum)!=mp.end()){
                int idx=mp[sum-rem_sum];
               longestSubArr = max(longestSubArr, i - mp[sum-rem_sum]);
            }
        }
        return longestSubArr==INT_MIN? -1:(n-longestSubArr);
    }
};