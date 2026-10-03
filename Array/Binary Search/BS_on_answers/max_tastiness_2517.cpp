class Solution {
public:
    bool canWePlace(int dist,vector<int>& a, int k){
        int count=1, last = a[0];
        for(int i=0;i<a.size();i++){
            if(a[i]-last >= dist){
                last = a[i];
                count++;
            }
            if(count == k)
                return true;
        }
        return false;
    }

    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int n=price.size();
        int low=0,high=price[n-1] - price[0];
        while(low<=high){
            int mid = low + (high - low)/2;
            if(canWePlace(mid,price,k) == true ){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};