class NumArray {
public:
    vector<int> arr;
    vector<int> block;
    int blocksize;
    // vector<int>prefix;
    NumArray(vector<int>& nums) {
        // int i=0;
        // int n=nums.size();
        // prefix.resize(n + 1);
        // prefix[0]=0;
        // for(i=0;i<n;i++){
        //     prefix[i+1]=prefix[i]+nums[i];
        // }
        arr=nums;
        int n=arr.size();
        blocksize=ceil(sqrt(n));
        int numBlocks = (n + blocksize - 1) / blocksize;
        block.resize(numBlocks, 0);
        for(int i=0;i<n;i++){
            block[i/blocksize]+=arr[i];
        }
    }
    
    int sumRange(int left, int right) {
        // return prefix[right+1]-prefix[left];
        int sum = 0;
        int startblock= left/blocksize, endblock=right/blocksize;
        if (startblock == endblock) {
        for (int i = left; i <= right; i++) {
                sum += arr[i];
            }
            return sum;
        }
        int i = left;

        while (i / blocksize == startblock) {
            sum += arr[i++];
        }

        for (i = startblock + 1; i < endblock; i++) {
            sum += block[i];
        }

        i = right;

        while (i / blocksize == endblock) {
            sum += arr[i--];
        }

        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */