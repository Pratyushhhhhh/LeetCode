class Solution {
public:

    void updateST(int i, int l, int r, int idx, vector<long long>&ST){
        if(l==r){
            ST[i]=1;//mark visited
            return;
        }
        int mid = l+(r-l)/2;
        if(idx<=mid){
            updateST(2*i+1,l,mid,idx,ST);
        }
        else{
            updateST(2*i+2,mid+1,r,idx,ST);
        }
        ST[i]=ST[2*i+1]+ST[2*i+2];
    }

    long long queryST(int start, int end, int i, int l, int r, vector<long long>&ST){
        if(l>end || r<start) return 0;
        if(l>=start && r<=end) return ST[i];
        int mid=l+(r-l)/2;
        int left=queryST(start,end,2*i+1,l,mid,ST);
        int right=queryST(start,end,2*i+2,mid+1,r,ST);
        return left+right;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int n= nums1.size();
        
        for(int i=0;i<n;i++){
            mp[nums2[i]]=i;
        }

        vector<long long>ST(4*n);
        long long result = 0;

        updateST(0,0,n-1,mp[nums1[0]],ST);

        for(int i=1;i<n;i++){
            int idx=mp[nums1[i]];
            long long leftCommonCount=queryST(0,idx,0,0,n-1,ST);
            long long leftUncommonCount=i-leftCommonCount;
            long long eleAfterIdx=(n-1)-idx;
            long long rightCommonCount= eleAfterIdx - leftUncommonCount;

            result +=leftCommonCount * rightCommonCount;

            updateST(0,0,n-1,idx,ST);
        }
        return result;
    }
    
};