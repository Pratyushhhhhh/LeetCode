class Solution {
public:
    int N,M,K;
    int t[51][51][101];
    int MOD = 1e9+7;
    int solve(int idx, int search_cost, int max_so_far){
        if(idx==N){
            if(search_cost==K){
                return 1;
            }
            return 0;
        }

        if(t[idx][search_cost][max_so_far]!=-1)
            return t[idx][search_cost][max_so_far];

        int res=0;
        for(int i=1;i<=M;i++){
            if(i>max_so_far){
                res=(res+solve(idx+1,search_cost+1,i))%MOD;
            }
            else{
                res=(res+solve(idx+1,search_cost,max_so_far))%MOD;
            }
        }    
        return t[idx][search_cost][max_so_far] = res%MOD;   
    }

    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(t,-1,sizeof(t));
        return solve(0,0,0);
    }
};