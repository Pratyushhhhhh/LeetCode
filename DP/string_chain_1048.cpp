class Solution {
public:
    // int n;
    // int t[1001][1001];
    bool checkPred(string a,string b){
        int n=a.size();
        int m=b.size();
        if(n >= m || m-n != 1) 
            return false;
        int i=0,j=0;
        while(i < n && j < m) {
            if(a[i] == b[j]) {
                i++;
                }
            j++;
        }
        return i == n;
    }
    // int solve(vector<string>& words, int i, int p){
    //     if(i==n)
    //         return 0;

    //     if(p!=-1 && t[i][p]!=-1)
    //         return t[i][p];

    //     int take=0;
    //     if(p==-1||checkPred(words[p],words[i])){
    //         take=1+solve(words,i+1,i);
    //     }

    //     int skip= solve(words,i+1,p);
    //     if(p!=-1)
    //         return t[i][p] = max(take,skip);
    //     return max(take,skip);
    // }
    // int longestStrChain(vector<string>& words) {
    //     n=words.size();
    //     sort(words.begin(), words.end(), [](string& a, string& b) {
    //     return a.length() < b.length();
    //     });
    //     memset(t,-1,sizeof(t));
    //     return solve(words,0,-1);
    // }

    //Bottom UP
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(), words.end(), [](string& a, string& b) {
        return a.length() < b.length();
        });

        vector<int>t(n,1);
        int maxLIS=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(checkPred(words[j],words[i])){
                    t[i]=max(t[i],t[j]+1);
                    maxLIS=max(maxLIS,t[i]);
                }
            }
        }
        return maxLIS;
    }
};