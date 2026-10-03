class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int cl=0,ccl=0;
        if(start>destination)
            swap(start,destination);
        for(int i=0;i<distance.size();i++){
            if(i>=start && i<destination) // if i b/w start and end therefore well go clockwise
                cl+=distance[i];
            else// else we'll go counter clockwise
                ccl+=distance[i];
        }
        return min(cl,ccl);
    }
};