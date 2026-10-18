class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxA=INT_MIN;
        int prefix = 0;
        maxA = max(maxA, prefix);
        for(auto &x:gain){
            prefix += x;
            maxA = max(maxA, prefix);
        }
        return maxA;
    }
};