class NumArray {

private:

public:
    int n;
    vector<int>ST;

    void buildtree(int l, int r, int i, vector<int>&nums){
        if(l==r){
            ST[i]=nums[l];
            return;
        }
        int mid = l+(r-l)/2;
        buildtree(l,mid,2*i+1,nums);
        buildtree(mid+1,r,2*i+2, nums);
        ST[i]=ST[2*i+1]+ST[2*i+2];
        return;
    }

    void updateST(int idx,int val, int i, int l,int r){
        if(l==r){
            ST[i]=val;
            return;
        }

        int mid=l+(r-l)/2;
        if(idx<=mid){
            updateST(idx,val,2*i+1,l,mid);
        }
        else{
            updateST(idx,val,2*i+2,mid+1,r);
        }

        ST[i]=ST[2*i+1]+ST[2*i+2];
    }

    int query(int left,int right, int i , int l, int  r){
        if(r<left || l>right) return 0;
        if(l>=left && r<=right) return ST[i];
        int mid=l+(r-l)/2;
        return query(left,right,2*i+1,l,mid) + query(left,right,2*i+2,mid+1,r);
    }

    NumArray(vector<int>& nums) {
        n=nums.size();
        int segsize= 2*pow(2,ceil(log2(n)))-1;
        ST.resize(segsize);
        buildtree(0,n-1,0,nums);
    }
    
    void update(int index, int val) {
        updateST(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return query(left, right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */