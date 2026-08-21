class Solution {
public:
    // int n;
    // int t[1001][1001];
    // int solve(vector<vector<int>> &pairs,int i, int p){
    //     if(i>=n) return 0;
    //     if(p!=-1 && t[i][p]!=-1) return t[i][p];

    //     int take=0;
    //     if(p==-1 || pairs[p][1] < pairs[i][0])
    //         take = 1 + solve(pairs,i+1,i);
    //     int skip = solve(pairs,i+1,p);

    //     if(p!=-1)
    //         return t[i][p]=max(take,skip);
    //     return max(take,skip);
    // }
    // int findLongestChain(vector<vector<int>>& pairs) {
    //      n=pairs.size();
    //      memset(t,-1,sizeof(t));
    //      sort(begin(pairs),end(pairs));
    //      return solve(pairs,0,-1);
    // }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
            int maxLIS=1;
            vector<int>t(n,1);
            sort(begin(pairs),end(pairs));
            for(int i=0;i<n;i++){
                for(int j=0;j<i;j++){
                    if(pairs[j][1]<pairs[i][0]){
                        t[i]=max(t[i],t[j]+1);
                        maxLIS=max(maxLIS,t[i]);
                    }
                }
            }
        return maxLIS;
    }
};