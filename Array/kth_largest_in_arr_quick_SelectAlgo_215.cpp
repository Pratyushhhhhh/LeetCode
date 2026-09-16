class Solution {
public:
    int partition_Algo(vector<int>&nums,int l,int r){
        int p=nums[l];
        int i=l+1;// when nums of size 1
        int j=r;

        while(i<=j){
            if(nums[i]<p && nums[j]>p){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            if(nums[i]>=p)
                i++;
            if(nums[j]<=p)
                j--;
        }
        swap(nums[j],nums[l]);
        return j;
    }

    int findKthLargest(vector<int>& nums, int k) {
        //Quick Select
        int n=nums.size();
        int L=0, R=n-1;

        int pivot_idx = 0;

        while(true){
        pivot_idx = partition_Algo(nums,L,R);
        if(pivot_idx == k-1){
            break;
        }else if(pivot_idx > k-1){
            R=pivot_idx-1;
        }else{
            L=pivot_idx+1;
        }
        }
        return nums[pivot_idx];

    }
};
        //brute using sort inn desc and returning nums[k-1] O(nlogn)

        //using min heap O(nlogk)
        // priority_queue<int, vector<int>, greater<int>> pq;  
        // for(int i=0;i<nums.size();i++){
        //     pq.push(nums[i]);
        //     if(pq.size()>k){
        //         pq.pop();
        //     }
        // }
        // return pq.top();
