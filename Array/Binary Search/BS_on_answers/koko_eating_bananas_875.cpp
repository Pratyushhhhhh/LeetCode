class Solution {
public:
    long long calchours(vector<int>& piles, int k) {
        long long totalH = 0;

        for (int i = 0; i < piles.size(); i++) {
            totalH += ceil((double)piles[i] / k);
        }

        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxE = *max_element(piles.begin(), piles.end());

        int low = 1;
        int high = maxE;
        int ans = maxE;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long totalH = calchours(piles, mid);

            if (totalH <= h) {
                // mid is a valid speed, try smaller
                ans = mid;
                high = mid - 1;
            } 
            else {
                // Need more speed
                low = mid + 1;
            }
        }

        return ans;
    }
};