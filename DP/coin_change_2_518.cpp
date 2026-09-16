class Solution {
public:
    int n;
    int dp[301][5001];
    int solve(vector<int>& coins,int i,int a){
        if(a==0)
            return 1;
        if(a<0 || i>=n)
            return 0;
        if(dp[i][a]!=-1)
            return dp[i][a];
        int stay = solve(coins,i,a-coins[i]);
        int next = solve(coins,i+1,a);

        return dp[i][a]=stay+next;
    }
    int change(int amount, vector<int>& coins) {
        n=coins.size();
        memset(dp,-1,sizeof(dp));
        int ans = solve(coins,0,amount);
        return ans;
    }
};