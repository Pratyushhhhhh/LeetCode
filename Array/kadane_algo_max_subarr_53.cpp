class Solution {
public:
    int maxSubArray(vector<int>& nums) { //KADANE ALGO
        int sum=0, maxSum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];

            if(sum>maxSum)
                maxSum=sum;
            
            if(sum<0) // taking -ve sum forward is not usefull so drop it
                sum=0;
        }
        return maxSum;
    }
};