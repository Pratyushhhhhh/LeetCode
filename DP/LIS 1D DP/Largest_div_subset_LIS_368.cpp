class Solution {
public:

    //Bottom-up 49/49 passed
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int n=nums.size();

        vector<int>t(n,1);
        vector<int>prev_idx(n,-1);

        int maxL=1;
        int last_idx=0;

        for(int i=0;i<n;i++){

            for(int j=0;j<i;j++){

                if(nums[i]%nums[j]==0)
                {
                    if(t[i]<t[j]+1){ 
                        t[i]=t[j]+1;
                        prev_idx[i]=j;
                    }
                
                    if(t[i]>maxL){
                        maxL=t[i];
                        last_idx=i;
                    }
                }
            }
        }
        vector<int>res;
        while(last_idx>=0){
            res.push_back(nums[last_idx]);
            last_idx=prev_idx[last_idx];
        }
        return res;
    }
    // Recursion 47/49 passed
    // void solve(int i,int p,vector<int>& res,vector<int>& temp,vector<int>& nums){
    //     if(i>=nums.size()){
    //         if(temp.size()>res.size())
    //         {
    //             res=temp;
    //         }
    //         return;
    //     }
    //     if(p==-1 || nums[i]%p==0){
    //         temp.push_back(nums[i]);
    //         solve(i+1,nums[i],res,temp,nums);
    //         temp.pop_back();
    //     }
    //     solve(i+1,p,res,temp,nums);
    // }

    // vector<int> largestDivisibleSubset(vector<int>& nums) {
    //     sort(begin(nums), end(nums));
    //     vector<int> res;
    //     vector<int> temp;
    //     int prev=-1;
    //     solve(0,prev,res,temp,nums);
    //     return res;
    // }
};