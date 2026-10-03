//Aggressive Cows
class Solution {
public:

    bool canWePlace(int dist,vector<int>& a, int m){
        int count=1, last = a[0];
        for(int i=0;i<a.size();i++){
            if(a[i]-last >= dist){
                last = a[i];
                count++;
            }
            if(count == m)
                return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int low=0,high=position[n-1] - position[0];
        while(low<=high){
            int mid = low + (high - low)/2;
            if(canWePlace(mid,position,m) == true ){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};