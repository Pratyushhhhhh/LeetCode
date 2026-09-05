class MedianFinder {
public:
    priority_queue<int> L_max_heap;
    priority_queue<int, vector<int>, greater<int>> R_min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(L_max_heap.empty() || num < L_max_heap.top()) {
            L_max_heap.push(num);
        }
        else{
            R_min_heap.push(num);
        }

        if(abs((int)L_max_heap.size()-(int)R_min_heap.size())>1){
            R_min_heap.push(L_max_heap.top());
            L_max_heap.pop();
        }
        else if(L_max_heap.size()<R_min_heap.size()){
            L_max_heap.push(R_min_heap.top());
            R_min_heap.pop();
        }
    }
    
    double findMedian() {
        if(L_max_heap.size()==R_min_heap.size()){
            double mean =(L_max_heap.top()+R_min_heap.top())/2.0;
            return mean;
        }
        return L_max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */