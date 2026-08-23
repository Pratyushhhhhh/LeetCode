class Solution {
public:
     long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        map<int, long long> mp;

        long long ans = INT_MIN;
        
        for(int i = 0; i < n; i++){
            auto it = mp.upper_bound(nums[i]-i); //next greater value in Ordered map 

            long long cur_ans = nums[i];

            if(it != mp.begin()) {//checks if we are not on top of the map
                it--;// past <= n[i]-i;
                cur_ans += it->second;// max_sum= it->sum;
            }
            mp[nums[i]-i] = max(mp[nums[i]-i], cur_ans);

            it = mp.upper_bound(nums[i]-i);

            while(it != mp.end() && it->second <= cur_ans) {
                 mp.erase(it++);
            }

            ans = max(ans, cur_ans);
        }

        return ans;
    }
};

