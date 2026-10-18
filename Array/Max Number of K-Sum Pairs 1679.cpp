class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int x:nums){
            mp[x]++;
        }
        int count=0;
        for(auto &it:mp){
            int x=it.first;
            if(mp[x]>0 && mp.find(k-x)!=mp.end()){
                if(x!=k-x){
                    count += min(mp[x],mp[k-x]);
                    mp[x]=0;
                    mp[k-x]=0;
                }
                else{
                    count += mp[x]/2;
                    mp[x]=0;
                }
            }
        }
        return count;
    }
};
//sort(nums.begin(), nums.end());
        // int n=nums.size();
        // int i=0,j=n-1;
        // int ans=0;
        // for(int i=0;i<n-1;i++){
        //     for(j=i+1;j<n;j++){
        //         if(nums[j]==-1)
        //             continue;
        //         if(nums[i]+nums[j]==k)
        //         {   
        //             ans++;
        //             nums[i]=-1;
        //             nums[j]=-1;
        //         }
        //     }
        // }
        // return ans;