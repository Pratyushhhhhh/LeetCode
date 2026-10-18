class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> p(n, 0);

        // p[0] = nums[0];

        // for (int i = 1; i < n; i++) {
        //     p[i] = p[i - 1] + nums[i];
        // }

        // for (int i = 0; i < n; i++) {
        //     if (i == 0) {
        //         if (p[n - 1] - p[i] == 0)
        //             return i;
        //     }
        //     else if (i == n - 1) {
        //         if (p[i - 1] == 0)
        //             return i;
        //     }
        //     else {
        //         if (p[i - 1] == p[n - 1] - p[i])
        //             return i;
        //     }
        // }

        // return -1;
         int total = 0, left = 0;

        for (int x : nums)
            total += x;

        for (int i = 0; i < nums.size(); i++) {
            if (left == total - left - nums[i])
                return i;

            left += nums[i];
        }

        return -1;

    }
};