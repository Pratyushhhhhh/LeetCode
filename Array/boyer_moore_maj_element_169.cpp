class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // boyer moore voting TC O(N) SC O(1)
        int candidate=0, count=0;
        for(auto num:nums){
            if(count==0)
                candidate=num;
            if(candidate==num)
                count++;
            else
                count--;
        }
        return candidate;
    }
};
// TC O(N) SC O(N)
        // unordered_map<int,int>mp;
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]++;
        // }
        // int maxFreq = INT_MIN;
        // int ans;
        // for(auto it:mp){
        //     if(it.second>maxFreq){
        //         maxFreq=it.second;
        //         ans=it.first;
        //     }
        // }
        // return ans;