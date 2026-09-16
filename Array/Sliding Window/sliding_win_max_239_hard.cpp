class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>deq;
        vector<int>res;
        for(int i=0;i<n;i++){
            //Make Space
            while(!deq.empty() && deq.front() <= i-k)
                deq.pop_front();
            //Clear smaller vals
            while(!deq.empty() && nums[i]>nums[deq.back()])
                deq.pop_back();
            //add next ele
            deq.push_back(i);
            //if in the window size then store ans
            if(i>=k-1)
                res.push_back(nums[deq.front()]);
        }
        return res;
    }
};