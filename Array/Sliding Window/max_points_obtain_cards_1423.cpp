class Solution {
public:
     
    int maxScore(vector<int>& cardPoints, int k) {
       int lsum=0,rsum=0;
       int n=cardPoints.size();
       int maxSum=0;
       for(int i=0;i<k;i++)
            lsum+=cardPoints[i];
        maxSum=lsum;
        int ridx=n-1;
       for(int i=k-1;i>=0;i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[ridx];
            ridx--;
            maxSum = max(maxSum,lsum+rsum);
       }
       return maxSum;
    }
};


// //Recusrion Memory Exceed
// vector<vector<int>> t;
//     int solve(vector<int>& nums, int l, int r, int k) {
//         if (k == 0)
//             return 0;
//         if(t[l][r]!=-1)
//             return t[l][r];
//         int takeFirst = nums[l] + solve(nums, l + 1, r, k - 1);
//         int takeLast  = nums[r] + solve(nums, l, r - 1, k - 1);

//         return t[l][r]=max(takeFirst, takeLast);
//     }
//  int n = cardPoints.size();
//         t.assign(n, vector<int>(n, -1));
//         return solve(cardPoints, 0, n - 1, k);