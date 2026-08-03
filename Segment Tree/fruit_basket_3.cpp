class Solution {
public:
    void buildST(int i,int l,int r,vector<int>& ST, vector<int>& baskets){
        if(l==r){
            ST[i]=baskets[l];
            return;
        }
        int mid=l+(r-l)/2;
        buildST(2*i+1,l,mid,ST,baskets);
        buildST(2*i+2,mid+1,r,ST,baskets);
        ST[i]=max(ST[2*i+1],ST[2*i+2]);
    }

    bool queryST(int i,int l,int r,vector<int>& ST, int fruit){
        if(ST[i]<fruit)
            return false;
        if(l==r){
            ST[i]=-1;
            return true;
        }
        int mid=l+(r-l)/2;
        bool placed = false;

        if(ST[2*i+1]>=fruit){
            placed = queryST(2*i+1,l,mid,ST,fruit);
        }
        else{
            placed = queryST(2*i+2,mid+1,r,ST,fruit);
        }

        ST[i]=max(ST[2*i+1],ST[2*i+2]);

        return placed;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<int>ST(4*n,-1);
        buildST(0,0,n-1,ST,baskets);
        int unplaced=0;
        for(int i=0;i<n;i++){
            if(queryST(0,0,n-1,ST,fruits[i])!=true)
                unplaced++;
        }
        return unplaced;
    }
};