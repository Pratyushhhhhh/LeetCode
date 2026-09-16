class Solution {
public:
    int mod = 1e9+7;
    void NSI(vector<int>&nsi,vector<int>&arr){
        stack<int>st;
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            nsi[i] = st.empty() ? n : st.top();
            st.push(i);            
        }
    }

    void PSI(vector<int>&psi,vector<int>&arr){
        stack<int>st;
        int n=arr.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();
            psi[i] = st.empty() ? -1 : st.top();
            st.push(i);            
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nsi(n,n);
        vector<int>psi(n,-1);
        NSI(nsi,arr);
        PSI(psi,arr);
        long long total = 0;

        for(int i=0; i<n; i++) {
            long long l = i - psi[i];
            long long r = nsi[i] - i;

            total = (total + (l * r % mod) * arr[i]) % mod;
        }
        return total;
    }
};