class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=0,r=n-1;
        while(l<r){
            int m=l+(r-l)/2;
            if(arr[m]<arr[m+1])
                l=m+1;
            else
                r=m;
        }
        return l;
        
    }
};
//Linear O(n)
// int i=0;
//         while(i<n-1 && arr[i]<arr[i+1]){
//             i++;
//         }
//         return i;