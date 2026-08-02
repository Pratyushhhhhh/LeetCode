class Solution {
public:

    void buildST(vector<int>&ST,vector<int>& heights,int i,int l, int r){
        if(l==r){
            ST[i]=l;
            return;
        }
        int mid=l+(r-l)/2;
        buildST(ST,heights,2*i+1,l,mid);
        buildST(ST,heights,2*i+2,mid+1,r);
        int lmax=ST[2*i+1], rmax=ST[2*i+2];
        if(heights[lmax]>=heights[rmax]){
            ST[i]=lmax;
        }
        else{
            ST[i]=rmax;
        }
        return;
    }

    int queryST(int start, int end, int i, int l, int r, const vector<int>& ST, const vector<int>& heights){
        if(l>end || r<start)
            return -1;
        if(l>=start && r<=end)
            return ST[i];
        int mid=l+(r-l)/2;
        int lmax=queryST(start,end,2*i+1,l,mid,ST,heights);
        int rmax=queryST(start,end,2*i+2,mid+1,r,ST,heights);
        if(lmax==-1)
            return rmax;
        if(rmax==-1)
            return lmax;
        if(heights[lmax]>=heights[rmax])
            return lmax;
        else
            return rmax;
    }

    int RMIQ(int a, int b, int n, const vector<int>& ST, const vector<int>& heights){
        return queryST(a,b,0,0,n-1,ST,heights);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n =  heights.size();
        int x = ceil(log2(n));
        int size=2*pow(2,x)-1;
        vector<int>ST(size);
        buildST(ST,heights,0,0,n-1);
        vector<int>ans;
        for(auto it:queries){
            int max_idx=max(it[0],it[1]);
            int min_idx=min(it[0],it[1]);
            if(max_idx==min_idx){
                ans.push_back(max_idx);
                continue;
            }
            else if(heights[max_idx]>heights[min_idx]){
               ans.push_back(max_idx);
               continue;
            }
            int l=max_idx+1, r=n-1,result_idx=INT_MAX;
            while(l<=r){
                int mid=l+(r-l)/2;
                int idx=RMIQ(l,mid,n,ST,heights);
                if(heights[idx]>heights[max_idx] && heights[idx]>heights[min_idx]){
                    result_idx=min(result_idx,idx);
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            if(result_idx==INT_MAX)
                ans.push_back(-1);
            else
                ans.push_back(result_idx);
        }
        return ans;
    }
};