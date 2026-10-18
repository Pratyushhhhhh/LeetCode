class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double mAvg = -DBL_MAX, sum=0;
        int i=0,j=0;
        int n= nums.size();
        while(j<n){
            if(j-i+1<=k)
                sum+=nums[j];
            if(j-i+1==k){
                mAvg = max(mAvg, sum/k);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return mAvg;
    }
};